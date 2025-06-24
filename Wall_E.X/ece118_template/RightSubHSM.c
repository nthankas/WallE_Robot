#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "TemplateHSM.h"
#include "RightSubHSM.h"
#include "Actuators.h"
#include "ES_Timers.h"

#define FAST 75
#define MID  65
#define SLOW 60

#define RIGHT_IR_DELAY 1500
static uint8_t irReady = 0;

#define RIGHT_HSM_TIMER 10
#define TURN_TIME     1200
#define FORWARD_TIME  500
#define BACK_TIME     400
#define ALIGN_DELAY   1500
#define APPROACH_TIME 2500
#define GRAB_WAIT     3850

static uint8_t rightIRReady = 0;
static ES_EventTyp_t detectedColor = COLOR_NOT_DETECTED;

typedef enum {
    InitPSubRightState,
    AlignCross,
    AlignCrossLeftIR,
    AlignCrossRightIR,
    ForwardPastCross,
    TurnRight,
    ReverseAlign,
    ReverseAlignLeftIR,
    ReverseAlignRightIR,
    BlockApproach,
    BlockGrab,
            CheckField,
    CrossCheck,
    ForwardCross,
    InverseRight,
    AlignCross2,
    AlignCross2LeftIR,
    AlignCross2RightIR,
    BackCross,
    ReturnBase,
    ReturnBaseLeftIR,
    ReturnBaseRightIR,
} RightSubHSMState_t;

static const char *StateNames[] = {
    "InitPSubRightState",
    "AlignCross",
    "AlignCrossLeftIR",
    "AlignCrossRightIR",
    "ForwardPastCross",
    "TurnRight",
    "ReverseAlign",
    "ReverseAlignLeftIR",
    "ReverseAlignRightIR",
    "BlockApproach",
    "BlockGrab",
    "CheckField",
    "CrossCheck",
    "ForwardCross",
    "InverseRight",
    "AlignCross2",
    "AlignCross2LeftIR",
    "AlignCross2RightIR",
    "BackCross",
    "ReturnBase",
    "ReturnBaseLeftIR",
    "ReturnBaseRightIR",
};

static RightSubHSMState_t CurrentState = InitPSubRightState;
static uint8_t MyPriority;

uint8_t InitRightSubHSM(void) {
    CurrentState = InitPSubRightState;
    printf("\nInitRightSubHSM: State set to %s\n", StateNames[CurrentState]);
    ES_Event returnEvent = RunRightSubHSM(INIT_EVENT);
    return (returnEvent.EventType == ES_NO_EVENT);
}

ES_Event RunRightSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    RightSubHSMState_t nextState = CurrentState;
    ES_Event returnEvent = { .EventType = ES_NO_EVENT };

    switch (CurrentState) {
        case InitPSubRightState:
            if (ThisEvent.EventType == ES_INIT) {
                nextState = AlignCross;
                makeTransition = TRUE;
            }
            break;

        case AlignCross:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(66);
                    RightMotor_SetSpeed(MID);
                    irReady = 0;
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, RIGHT_IR_DELAY);
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
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
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
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
                    LeftMotor_SetSpeed(61);
                    RightMotor_SetSpeed(59);
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, FORWARD_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
                        nextState = TurnRight;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
                    break;
            }
            break;

        case TurnRight:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(60);
                    RightMotor_SetSpeed(-61);
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, TURN_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
                        LeftMotor_SetSpeed(0);
                        RightMotor_SetSpeed(0);
                        nextState = ReverseAlign;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
                    break;
            }
            break;

        case ReverseAlign:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-62);
                    RightMotor_SetSpeed(-SLOW);
//                    irReady = 0;
//                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, RIGHT_IR_DELAY);
                    break;

//                case ES_TIMEOUT:
//                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
//                        irReady = 1;
//                        printf("ReverseAlign: IR now active\n");
//                    }
//                    break;

                case IR_LEFT_ON_LINE:
//                    if (irReady) {
                        LeftMotor_SetSpeed(0);
                        nextState = ReverseAlignLeftIR;
                        makeTransition = TRUE;
//                    }
                    break;

                case IR_RIGHT_ON_LINE:
//                    if (irReady) {
                        RightMotor_SetSpeed(0);
                        nextState = ReverseAlignRightIR;
                        makeTransition = TRUE;
//                    }
                    break;

                case ES_EXIT:
//                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
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
                    printf("BlockApproach: Driving forward with timer\n");
                    LeftMotor_SetSpeed(MID);
                    RightMotor_SetSpeed(MID);
                    break;
                    
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
                    LeftMotor_SetSpeed(51);
                    RightMotor_SetSpeed(50);
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, GRAB_WAIT);
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
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
                        printf("\nTIME___OUT color not detected");
                        detectedColor = COLOR_NOT_DETECTED;
                        nextState = CheckField;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    break;
            }
            break;
        case CheckField:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    printf("CheckField: using IR sensors\n");
                    LeftMotor_SetSpeed(-64);
                    RightMotor_SetSpeed(-MID);
                    break;

                case IR_LEFT_ON_LINE:
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
                    LeftMotor_SetSpeed(-64);
                    RightMotor_SetSpeed(-MID);
                    break;
                case IR_RIGHT_ON_LINE:
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
                    LeftMotor_SetSpeed(64);
                    RightMotor_SetSpeed(MID);
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, FORWARD_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
                        nextState = InverseRight;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
                    break;
            }
            break;

        case InverseRight:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-61);
                    RightMotor_SetSpeed(SLOW);
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, TURN_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
                        nextState = AlignCross2;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
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
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
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
                    LeftMotor_SetSpeed(-MID);
                    RightMotor_SetSpeed(-MID);
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, BACK_TIME);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
                        nextState = ReturnBase;
                        makeTransition = TRUE;
                    }
                    break;
                case ES_EXIT:
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
                    break;
            }
            break;

        case ReturnBase:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-66);
                    RightMotor_SetSpeed(-MID);
                    irReady = 0;
                    ES_Timer_InitTimer(RIGHT_HSM_TIMER, RIGHT_IR_DELAY);
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == RIGHT_HSM_TIMER) {
                        irReady = 1;
                        printf("ReturnBase: IR now active\n");
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
                    ES_Timer_StopTimer(RIGHT_HSM_TIMER);
                    break;
            }
            break;

        case ReturnBaseLeftIR:
            if (ThisEvent.EventType == IR_RIGHT_ON_LINE) {
                RightMotor_SetSpeed(0);
                returnEvent.EventType = RIGHT_DONE;
                return returnEvent;
            }
            break;

        case ReturnBaseRightIR:
            if (ThisEvent.EventType == IR_LEFT_ON_LINE) {
                LeftMotor_SetSpeed(0);
                returnEvent.EventType = RIGHT_DONE;
                return returnEvent;
            }
            break;
    }

    if (makeTransition) {
        RunRightSubHSM(EXIT_EVENT);
        CurrentState = nextState;
        RunRightSubHSM(ENTRY_EVENT);
    }

    return ThisEvent;
}

ES_EventTyp_t RightSubHSM_GetDetectedColor(void) {
    return detectedColor;
}
