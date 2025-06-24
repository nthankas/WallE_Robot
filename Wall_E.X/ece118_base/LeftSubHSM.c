#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "TemplateHSM.h"
#include "LeftSubHSM.h"
#include "Actuators.h"
#include "ES_Timers.h"


#define FAST 75
#define MID  65
#define SLOW 60

#define IR_DELAY 295
static uint8_t irReady = 0;


#define LEFT_HSM_TIMER 8
#define TURN_TIME     1200
#define FORWARD_TIME  500
#define BACK_TIME     400 // 700 works with no alignment
#define ALIGN_DELAY   1500
#define APPROACH_TIME 2500
#define GRAB_WAIT     3850

static uint8_t leftIRReady = 0;
static ES_EventTyp_t detectedColor = COLOR_NOT_DETECTED;

typedef enum {
    InitPSubLeftState,
    AlignCross,
    AlignCrossLeftIR,
    AlignCrossRightIR,
    ForwardPastCross,
    TurnLeft,
    ReverseAlign,
    ReverseAlignLeftIR,
    ReverseAlignRightIR,
    BlockApproach,
    BlockGrab,
            CheckField,
    CrossCheck,
    ForwardCross,
    InverseLeft,
    AlignCross2,
    AlignCross2LeftIR,
    AlignCross2RightIR,
    BackCross,
    ReturnBase,
    ReturnBaseLeftIR,
    ReturnBaseRightIR,
            
} LeftSubHSMState_t;

static const char *StateNames[] = {
    "InitPSubLeftState",
    "AlignCross",
    "AlignCrossLeftIR",
    "AlignCrossRightIR",
    "ForwardPastCross",
    "TurnLeft",
    "ReverseAlign",
    "ReverseAlignLeftIR",
    "ReverseAlignRightIR",
    "BlockApproach",
    "BlockGrab",
    "CheckField",
    "CrossCheck",
    "ForwardCross",
    "InverseLeft",
    "AlignCross2",
    "AlignCross2LeftIR",
    "AlignCross2RightIR",
    "BackCross",
    "ReturnBase",
    "ReturnBaseLeftIR",
    "ReturnBaseRightIR",
};

static LeftSubHSMState_t CurrentState = InitPSubLeftState;
static uint8_t MyPriority;

#define STARTUP_IR_IGNORE_TIME 500
static uint8_t IRReady = 0;

uint8_t InitLeftSubHSM(void) {
    CurrentState = InitPSubLeftState;
    //printf("\nInitLeftSubHSM: State set to %s\n", StateNames[CurrentState]);
    ES_Event returnEvent = RunLeftSubHSM(INIT_EVENT);
    return (returnEvent.EventType == ES_NO_EVENT);
}

ES_Event RunLeftSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    LeftSubHSMState_t nextState = CurrentState;
    ES_Event returnEvent = { .EventType = ES_NO_EVENT };

    switch (CurrentState) {
        case InitPSubLeftState:
            if (ThisEvent.EventType == ES_INIT) {
                nextState = AlignCross;
                makeTransition = TRUE;
            }
            break;

        case AlignCross:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(67);
                    RightMotor_SetSpeed(MID);
                    irReady = 0;
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, IR_DELAY);
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        irReady = 1;
                        printf("AlignCross: IR now active\n");
                    }
                    break;

                case IR_LEFT_ON_LINE:
                    if (irReady) {
                        LeftMotor_SetSpeed(0);
                        nextState = AlignCrossLeftIR;
                        makeTransition = TRUE;
                    }
                    break;

                case IR_RIGHT_ON_LINE:
                    if (irReady) {
                        RightMotor_SetSpeed(0);
                        nextState = AlignCrossRightIR;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;


        case AlignCrossLeftIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("AlignCrossLeftIR: Waiting for RIGHT IR\n");
                    break;

                case IR_RIGHT_ON_LINE:
                    printf("AlignCrossLeftIR: RIGHT IR hit -> stopping right motor\n");
                    RightMotor_SetSpeed(0);
                    nextState = ForwardPastCross;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case AlignCrossRightIR:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("AlignCrossRightIR: Waiting for LEFT IR\n");
                    break;

                case IR_LEFT_ON_LINE:
                    printf("AlignCrossRightIR: LEFT IR hit -> stopping left motor\n");
                    LeftMotor_SetSpeed(0);
                    nextState = ForwardPastCross;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case ForwardPastCross:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(62);
                    RightMotor_SetSpeed(SLOW);
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, FORWARD_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        nextState = TurnLeft;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;

        case TurnLeft:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-62);
                    RightMotor_SetSpeed(SLOW);
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, TURN_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        LeftMotor_SetSpeed(0);
                        RightMotor_SetSpeed(0);
                        nextState = ReverseAlign;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;

        case ReverseAlign:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-62);
                    RightMotor_SetSpeed(-SLOW);
                    irReady = 0;
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, IR_DELAY);
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        irReady = 1;
                        printf("ReverseAlign: IR now active\n");
                    }
                    break;

                case IR_LEFT_ON_LINE:
                    if (irReady) {
                        LeftMotor_SetSpeed(0);
                        nextState = ReverseAlignLeftIR;
                        makeTransition = TRUE;
                    }
                    break;

                case IR_RIGHT_ON_LINE:
                    if (irReady) {
                        RightMotor_SetSpeed(0);
                        nextState = ReverseAlignRightIR;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;


        case ReverseAlignLeftIR:
            if (ThisEvent.EventType == IR_RIGHT_ON_LINE) {
                RightMotor_SetSpeed(0);
                nextState = BlockApproach;
                makeTransition = TRUE;
            }
            break;

        case ReverseAlignRightIR:
            if (ThisEvent.EventType == IR_LEFT_ON_LINE) {
                LeftMotor_SetSpeed(0);
                nextState = BlockApproach;
                makeTransition = TRUE;
            }
            break;

        case BlockApproach:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(65);
                    RightMotor_SetSpeed(63);
                    break;
                    
                case IR_RIGHT_ON_LINE:
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
                    LeftMotor_SetSpeed(55);
                    RightMotor_SetSpeed(55);
                    printf("BlockGrab: waiting for color\n");
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, GRAB_WAIT);
                    break;
                case COLOR_DETECTED_RED:
                case COLOR_DETECTED_BLUE:
                    detectedColor = ThisEvent.EventType;
                    ServoGrab(0);
                    nextState = CheckField;
                    makeTransition = TRUE;
                    break;
                case COLOR_DETECTED_GREEN:
                    detectedColor = COLOR_DETECTED_GREEN;
                    nextState = CheckField;
                    makeTransition = TRUE;
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        
                        detectedColor = COLOR_NOT_DETECTED;
                        nextState = CheckField;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    break;
            }
            break;
        case CheckField:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("CheckField: using IR sensors\n");
                    LeftMotor_SetSpeed(-66);
                    RightMotor_SetSpeed(-MID);
                    break;

                case IR_RIGHT_ON_LINE:
                    printf("CheckField: Any IR detected line continue\n");
                        nextState = CrossCheck;
                        makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case CrossCheck:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-66);
                    RightMotor_SetSpeed(-MID);
                    break;
                case IR_LEFT_ON_LINE:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = ForwardCross;
                    makeTransition = TRUE;
                    break;
            }
            break;

        case ForwardCross:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(MID);
                    RightMotor_SetSpeed(MID);
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, FORWARD_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        nextState = InverseLeft;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;

        case InverseLeft:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(SLOW);
                    RightMotor_SetSpeed(-61);
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, TURN_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        nextState = AlignCross2;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    break;
            }
            break;

        case AlignCross2:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-MID);
                    RightMotor_SetSpeed(-MID);
                    break;


                case IR_LEFT_ON_LINE:
                        LeftMotor_SetSpeed(0);
                        nextState = AlignCross2LeftIR;
                        makeTransition = TRUE;
                    break;

                case IR_RIGHT_ON_LINE:
                        RightMotor_SetSpeed(0);
                        nextState = AlignCross2RightIR;
                        makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;


        case AlignCross2LeftIR:
            if (ThisEvent.EventType == IR_RIGHT_ON_LINE) {
                RightMotor_SetSpeed(0);
                nextState = BackCross;
                makeTransition = TRUE;
            }
            break;

        case AlignCross2RightIR:
            if (ThisEvent.EventType == IR_LEFT_ON_LINE) {
                LeftMotor_SetSpeed(0);
                nextState = BackCross;
                makeTransition = TRUE;
            }
            break;
        
        case BackCross:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-66);
                    RightMotor_SetSpeed(-MID);
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, BACK_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        nextState = ReturnBase;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;
        
        case ReturnBase:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-67);
                    RightMotor_SetSpeed(-MID);
                    irReady = 0;
                    ES_Timer_InitTimer(LEFT_HSM_TIMER, IR_DELAY);
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == LEFT_HSM_TIMER) {
                        irReady = 1;
                        printf("ReturnLeft: IR now active\n");
                    }
                    break;

                case IR_LEFT_ON_LINE:
                    if (irReady) {
                        LeftMotor_SetSpeed(0);
                        nextState = ReturnBaseLeftIR;
                        makeTransition = TRUE;
                    }
                    break;

                case IR_RIGHT_ON_LINE:
                    if (irReady) {
                        RightMotor_SetSpeed(0);
                        nextState = ReturnBaseRightIR;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(LEFT_HSM_TIMER);
                    break;
            }
            break;


        case ReturnBaseLeftIR:
            if (ThisEvent.EventType == IR_RIGHT_ON_LINE) {
                RightMotor_SetSpeed(0);
                returnEvent.EventType = LEFT_DONE;
                return returnEvent;
            }
            break;

        case ReturnBaseRightIR:
            if (ThisEvent.EventType == IR_LEFT_ON_LINE) {
                LeftMotor_SetSpeed(0);
                returnEvent.EventType = LEFT_DONE;
                return returnEvent;
            }
            break;
    }

    if (makeTransition) {
        RunLeftSubHSM(EXIT_EVENT);
        CurrentState = nextState;
        RunLeftSubHSM(ENTRY_EVENT);
    }

    return ThisEvent;
}

ES_EventTyp_t LeftSubHSM_GetDetectedColor(void) {
    return detectedColor;
}
