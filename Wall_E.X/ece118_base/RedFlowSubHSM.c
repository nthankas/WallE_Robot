#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "TemplateHSM.h"
#include "RedFlowSubHSM.h"
//#include "GrabSubHSM.h"
#include "Actuators.h"
#include "ES_Timers.h"

#define RED_TURN_TIME 1100     // ms to turn right was 600
#define DROP_DELAY 1050        // ms to wait for drop was 500
#define BACK_DELAY 1050         // ms
#define CENTER_TURN_TIME 1050  // ms to turn back
#define FORWARD_DELAY 1050
#define REFORWARD_DELAY 950 


#define STRAIGHT_SPEED 75
#define TURN_SPEED 65

#define RED_TIMER 7


typedef enum {
    InitPRedFlowSubState,
    TurnLeft,
    DropRed,
            MoveForward,
            MoveBack,
    TurnAlign,
    CenterRed,
    AlignRed,
    AlignRedLeftIR,
    AlignRedRightIR,
    ForwardPastLine,
    ReForward,
} RedFlowSubHSMState_t;

static const char *StateNames[] = {
    "InitPRedFlowSubState",
    "TurnLeft",
    "DropRed",
    "MoveForward",
    "MoveBack",
    "TurnAlign",
    "CenterRed",
    "AlignRed",
    "AlignRedLeftIR",
    "AlignRedRightIR",
    "ForwardPastLine",
    "ReForward",
};

static RedFlowSubHSMState_t CurrentState = InitPRedFlowSubState;
static uint8_t MyPriority;

uint8_t InitRedFlowSubHSM(void)
{
    ES_Event returnEvent;
    CurrentState = InitPRedFlowSubState;
    printf("InitApproachSubHSM: State set to %s\n", StateNames[CurrentState]);
    returnEvent = RunRedFlowSubHSM(INIT_EVENT);
    return (returnEvent.EventType == ES_NO_EVENT);
}

ES_Event RunRedFlowSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE;
    RedFlowSubHSMState_t nextState = CurrentState;
    ES_Event returnEvent = { .EventType = ES_NO_EVENT };

    ES_Tattle();
    printf("RunRedFlowSubHSM(%s[%X]);\n", StateNames[CurrentState], ThisEvent.EventType);

    switch (CurrentState) {
        case InitPRedFlowSubState:
            if (ThisEvent.EventType == ES_INIT) {
                ES_EventTyp_t color = GetDetectedColor();
                if (color == COLOR_DETECTED_GREEN) {
                    nextState = ReForward;
                } else {
                    nextState = TurnLeft;
                }
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                printf("Transition: InitPSubApproachState -> DriveForwardState\n");
            }
            break;

        case TurnLeft:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("Entering TurnLeft\n");
                    LeftMotor_SetSpeed(-TURN_SPEED);
                    RightMotor_SetSpeed(TURN_SPEED);
                    ES_Timer_InitTimer(RED_TIMER, RED_TURN_TIME);
                    break;

                case ES_TIMEOUT:
                    nextState = DropRed;
                    ServoGrab(1);  // Release block
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    ES_Timer_StopTimer(RED_TIMER);
                    break;
            }
            break;
            
        case DropRed:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
//                    LeftMotor_SetSpeed(STRAIGHT_SPEED);
//                    RightMotor_SetSpeed(STRAIGHT_SPEED);
//                    printf("Entering DropRed\n");
                    ES_Timer_InitTimer(RED_TIMER, RED_TURN_TIME);
                    break;

                case ES_TIMEOUT:
//                    LeftMotor_SetSpeed(0);
//                    RightMotor_SetSpeed(0);
                    nextState = MoveForward;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(RED_TIMER);
                    break;
            }
            break;
        case MoveForward:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(STRAIGHT_SPEED);
                    RightMotor_SetSpeed(STRAIGHT_SPEED);
                    printf("LEaving item\n");
                    ES_Timer_InitTimer(RED_TIMER, BACK_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = MoveBack;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(RED_TIMER);
                    break;
            }
            break;
        
        case MoveBack:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-STRAIGHT_SPEED);
                    RightMotor_SetSpeed(-STRAIGHT_SPEED);
                    printf("Leaving part 2 item\n");
                    ES_Timer_InitTimer(RED_TIMER, DROP_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = TurnAlign;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(RED_TIMER);
                    break;
            }
            break;
            
        case TurnAlign:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(TURN_SPEED);
                    RightMotor_SetSpeed(-TURN_SPEED);
                    printf("Entering TurnAlign\n");
                    ES_Timer_InitTimer(RED_TIMER, BACK_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = ForwardPastLine;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(RED_TIMER);
                    break;
            }
            break;
            
//        case CenterRed:
//            switch (ThisEvent.EventType) {
//                case ES_ENTRY:
//                    printf("Entering CenterRed\n");
//                    LeftMotor_SetSpeed(TURN_SPEED);
//                    RightMotor_SetSpeed(-TURN_SPEED);
//                    ES_Timer_InitTimer(RED_TIMER, CENTER_TURN_TIME);
//                    break;
//
//                case ES_TIMEOUT:
//                    printf("Center complete -> returning COMPLETE to SortSubHSM\n");
//                    LeftMotor_SetSpeed(0);
//                    RightMotor_SetSpeed(0);
//                    
//                    nextState = ReForward;
//                    makeTransition = TRUE;
//
//                case ES_EXIT:
//                    ES_Timer_StopTimer(RED_TIMER);
//                    break;
//            }
//            break;
            
        case ForwardPastLine:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(STRAIGHT_SPEED);
                    RightMotor_SetSpeed(STRAIGHT_SPEED);
                    printf("Entering Forward\n");
                    ES_Timer_InitTimer(RED_TIMER, FORWARD_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = AlignRed;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(RED_TIMER);
                    break;
            }
            break;
            
        case AlignRed:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("Entering ReturnHome\n");
                    LeftMotor_SetSpeed(-STRAIGHT_SPEED);
                    RightMotor_SetSpeed(-STRAIGHT_SPEED);
//                    NOP_Delay(10000);
                    break;

                case IR_LEFT_ON_LINE:
                    printf("Left IR hit first -> stopping left motor\n");
                    LeftMotor_SetSpeed(0);
                    nextState = AlignRedLeftIR;
                    makeTransition = TRUE;
                    break;

                case IR_RIGHT_ON_LINE:
                    printf("Right IR hit first -> stopping right motor\n");
                    RightMotor_SetSpeed(0);
                    nextState = AlignRedRightIR;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    printf("Exit ReturnHome\n");
                    break;
            }
            break;
        
        case AlignRedLeftIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("Entered ReturnLeftWaiting -> waiting for RIGHT IR\n");
                    break;

                case IR_RIGHT_ON_LINE:
                    printf("Right IR hit ? stopping right motor\n");
                    RightMotor_SetSpeed(0);
                    
                    returnEvent.EventType = RED_FLOW_DONE;
                    return returnEvent;
                    break;

                case ES_EXIT:
                    break;
            }
            break;
        case AlignRedRightIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("Entered ReturnRightWaiting ? waiting for LEFT IR\n");
                    break;

                case IR_LEFT_ON_LINE:
                    printf("Left IR hit ? stopping left motor\n");
                    LeftMotor_SetSpeed(0);
                    returnEvent.EventType = RED_FLOW_DONE;
                    return returnEvent;
                    break;

                case ES_EXIT:
                    break;
            }
            break;
            
        case ReForward:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(STRAIGHT_SPEED);
                    RightMotor_SetSpeed(STRAIGHT_SPEED);
                    printf("Entering ReForward\n");
                    ES_Timer_InitTimer(RED_TIMER, REFORWARD_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = AlignRed;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(RED_TIMER);
                    break;
            }
            break;

        default:
            break;
    }

    if (makeTransition == TRUE) {
        RunRedFlowSubHSM(EXIT_EVENT);
        CurrentState = nextState;
        printf("Transitioning to %s\n", StateNames[CurrentState]);
        RunRedFlowSubHSM(ENTRY_EVENT);
    }

    ES_Tail();
    return ThisEvent;
}
