#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"

#include "TemplateHSM.h"
#include "CenterSubHSM.h"
#include "LeftSubHSM.h"
#include "Actuators.h"
#include "ES_Timers.h"

#define FAST 75
#define MID  65
#define SLOW 60

#define APPROACHSPEED 50

#define CENTER_IR_TIMER 9
#define CENTER_IR_DELAY 1500 // ms
static uint8_t centerIRReady = 0;

static ES_EventTyp_t detectedColor = COLOR_NOT_DETECTED;

typedef enum {
    InitPSubCenterState,
    AlignCenter,
    AlignCenterLeftIR,
    AlignCenterRightIR,
    BlockApproach,
    BlockGrab,
            CheckField,
    CheckCenter,
    ReturnCenter,
    ReturnCenterLeftIR,
    ReturnCenterRightIR,
} CenterSubHSMState_t;

static const char *StateNames[] = {
    "InitPSubCenterState",
    "AlignCenter",
    "AlignCenterLeftIR",
    "AlignCenterRightIR",
    "BlockApproach",
    "BlockGrab",
    "CheckField",
    "CheckCenter",
    "ReturnCenter",
    "ReturnCenterLeftIR",
    "ReturnCenterRightIR",
};

static CenterSubHSMState_t CurrentState = InitPSubCenterState;
static uint8_t MyPriority;

uint8_t InitCenterSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = InitPSubCenterState;
    //printf("\nInitCenterSubHSM: State set to %s\n", StateNames[CurrentState]);
    returnEvent = RunCenterSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunCenterSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE;
    CenterSubHSMState_t nextState = CurrentState;
    ES_Event returnEvent = { .EventType = ES_NO_EVENT }; // Add this line

    ES_Tattle();
    //printf("RunCenterSubHSM(%s[%X]);\n", StateNames[CurrentState], ThisEvent.EventType);

    switch (CurrentState) {
        case InitPSubCenterState:
            if (ThisEvent.EventType == ES_INIT) {
                nextState = AlignCenter;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                printf("Transition: InitPCenterSubState -> AlignCenter\n");
            }
            break;

        case AlignCenter:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("AlignCenter: Driving forward\n");
                    LeftMotor_SetSpeed(67);
                    RightMotor_SetSpeed(MID);
                    break;

                case IR_LEFT_ON_LINE:
                    printf("AlignCenter: LEFT IR detected -> stopping left motor\n");
                    LeftMotor_SetSpeed(0);
                    nextState = AlignCenterLeftIR;
                    makeTransition = TRUE;
                    break;

                case IR_RIGHT_ON_LINE:
                    printf("AlignCenter: RIGHT IR detected -> stopping right motor\n");
                    RightMotor_SetSpeed(0);
                    nextState = AlignCenterRightIR;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case AlignCenterLeftIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("AlignCenterLeftIR: Waiting for RIGHT IR\n");
                    break;

                case IR_RIGHT_ON_LINE:
                    printf("AlignCenterLeftIR: RIGHT IR hit -> stopping right motor\n");
                    RightMotor_SetSpeed(0);
                    nextState = BlockApproach;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case AlignCenterRightIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("AlignCenterRightIR: Waiting for LEFT IR\n");
                    break;

                case IR_LEFT_ON_LINE:
                    printf("AlignCenterRightIR: LEFT IR hit -> stopping left motor\n");
                    LeftMotor_SetSpeed(0);
                    nextState = BlockApproach;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;


        case BlockApproach:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("BlockApproach: Driving forward with timer\n");
                    LeftMotor_SetSpeed(65);
                    RightMotor_SetSpeed(60);
                    break;
                    
                case IR_RIGHT_ON_LINE:
                case IR_LEFT_ON_LINE:
                    printf("BlockApproach: Border reached -> transitioning to BlockGrab\n");
                    nextState = BlockGrab;
                    makeTransition = TRUE;
                    break;
                case ES_EXIT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    break;
            }
            break;
            
        case BlockGrab:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(CENTER_IR_TIMER, 2350);
                    printf("BlockGrab: sensing color\n");
                    LeftMotor_SetSpeed(52);
                    RightMotor_SetSpeed(APPROACHSPEED);
                    break;
          
                    
                case COLOR_DETECTED_RED:
                case COLOR_DETECTED_BLUE:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    printf("BlockGrab: RED BLUE detected -> ReturnCenter\n");
                    detectedColor = ThisEvent.EventType;
                    ServoGrab(0); // GRAB BLOCK
                    nextState = CheckField;
                    makeTransition = TRUE;
                    break;
                    
                case COLOR_DETECTED_GREEN:
                    printf("BlockGrab: GREEN detected -> ReturnCenter\n");
                    detectedColor = COLOR_DETECTED_GREEN;
                    nextState = CheckField;
                    makeTransition = TRUE;
                    break; 
                
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == CENTER_IR_TIMER) {
                        printf("BlockGrab: timeout ? no color detected\n");
                        detectedColor = COLOR_NOT_DETECTED; // FOR DEMO
                        nextState = CheckField;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(CENTER_IR_TIMER);
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    break;


                default:
                    break;
            }
            break;
            
         case CheckField:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("CheckField: using IR sensors\n");
                    LeftMotor_SetSpeed(-65);
                    RightMotor_SetSpeed(-65);
                    break;

                case IR_LEFT_ON_LINE:
                case IR_RIGHT_ON_LINE:
                    printf("CheckField: Any IR detected line continue\n");
                        nextState = CheckCenter;
                        makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;
        case CheckCenter:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("CheckCenter: using IR sensors\n");
                    LeftMotor_SetSpeed(-65);
                    RightMotor_SetSpeed(-64);
                    break;

                case IR_LEFT_ON_LINE:
                case IR_RIGHT_ON_LINE:
                        printf("CheckCenter: Both IRs detected -> continuing\n");
                        nextState = ReturnCenter;
                        makeTransition = TRUE;
                        break;
            case ES_EXIT:
                break;
        }
        break;

        case ReturnCenter:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("ReturnCenter: Driving backwards\n");
                    LeftMotor_SetSpeed(-65);
                    RightMotor_SetSpeed(-64);
                    centerIRReady = 0;
                    ES_Timer_InitTimer(CENTER_IR_TIMER, CENTER_IR_DELAY);
                    break;
                    
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == CENTER_IR_TIMER) {
                        printf("ReturnCenter: IR check enabled\n");
                        centerIRReady = 1;
                    }
                    break;

                case IR_LEFT_ON_LINE:
                    if (centerIRReady) {
                        printf("ReturnCenter: LEFT IR detected -> stopping left motor\n");
                        LeftMotor_SetSpeed(0);
                        nextState = ReturnCenterLeftIR;
                        makeTransition = TRUE;
                    }
                    break;

                case IR_RIGHT_ON_LINE:
                    if (centerIRReady) {
                        printf("ReturnCenter: RIGHT IR detected -> stopping right motor\n");
                        RightMotor_SetSpeed(0);
                        nextState = ReturnCenterRightIR;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(CENTER_IR_TIMER);
                    break;
            }
            break;

        case ReturnCenterLeftIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("ReturnCenterLeftIR: Waiting for RIGHT IR\n");
                    break;

                case IR_RIGHT_ON_LINE:
                    printf("ReturnCenterLeftIR: RIGHT IR hit -> stopping right motor\n");
                    RightMotor_SetSpeed(0);
                    returnEvent.EventType = CENTER_DONE;
                    return returnEvent;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case ReturnCenterRightIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("ReturnCenterRightIR: Waiting for LEFT IR\n");
                    break;

                case IR_LEFT_ON_LINE:
                    printf("ReturnCenterRightIR: LEFT IR hit -> stopping left motor\n");
                    LeftMotor_SetSpeed(0);
                    returnEvent.EventType = CENTER_DONE;
                    return returnEvent;
                    break;

                case ES_EXIT:
                    break;
            }
            break;
    }

    if (makeTransition == TRUE) {
        RunCenterSubHSM(EXIT_EVENT);
        CurrentState = nextState;
        printf("Transitioning to %s\n", StateNames[CurrentState]);
        RunCenterSubHSM(ENTRY_EVENT);
    }

    ES_Tail();
    return ThisEvent;
}

ES_EventTyp_t CenterSubHSM_GetDetectedColor(void) {
    return detectedColor;
}