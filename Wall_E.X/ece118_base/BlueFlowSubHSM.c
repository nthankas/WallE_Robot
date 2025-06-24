#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "BlueFlowSubHSM.h"
#include "Actuators.h"
#include "ES_Timers.h"

#define BLUE_TURN_TIME 1100     // ms to turn left
#define DROP_DELAY 1050          // ms to wait for drop
#define BACK_DELAY 1200           // ms
#define CENTER_TURN_TIME 1200    // ms to turn back
#define FORWARD_DELAY 1200        // ms
#define REFORWARD_DELAY 950

#define STRAIGHT_SPEED 75
#define TURN_SPEED 67

#define BLUE_TIMER 13

typedef enum {
    InitPBlueFlowSubState,
    TurnRight,
    DropBlock,
    MoveForward,
    MoveBack,
            TurnAlign,
            CenterBlue,
            AlignBlue,
    ForwardPastLine,
    AlignCenter,
    AlignLeftWaiting,
    AlignRightWaiting,
    ReForward,
} BlueFlowSubHSMState_t;

static const char *StateNames[] = {
    "InitPBlueFlowSubState",
    "TurnRight",
    "DropBlock",
    "MoveForward",
    "MoveBack",
    "TurnAlign",
    "CenterBlue",
    "AlignBlue",
            "ForwardPastLine",
    "AlignCenter",
    "AlignLeftWaiting",
    "AlignRightWaiting",
    "ReForward",
};

static BlueFlowSubHSMState_t CurrentState = InitPBlueFlowSubState;
static uint8_t MyPriority;

uint8_t InitBlueFlowSubHSM(void)
{
    ES_Event returnEvent;
    CurrentState = InitPBlueFlowSubState;
    printf("InitBlueFlowSubHSM: State set to %s\n", StateNames[CurrentState]);
    returnEvent = RunBlueFlowSubHSM(INIT_EVENT);
    return (returnEvent.EventType == ES_NO_EVENT);
}

ES_Event RunBlueFlowSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE;
    BlueFlowSubHSMState_t nextState = CurrentState;
    ES_Event returnEvent = { .EventType = ES_NO_EVENT };

    ES_Tattle();
    printf("RunBlueFlowSubHSM(%s[%X]);\n", StateNames[CurrentState], ThisEvent.EventType);

    switch (CurrentState) {
        case InitPBlueFlowSubState:
            if (ThisEvent.EventType == ES_INIT) {
                nextState = TurnRight;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                printf("Transition: Init -> TurnRight\n");
            }
            break;

        case TurnRight:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(TURN_SPEED);
                    RightMotor_SetSpeed(-TURN_SPEED);
                    ES_Timer_InitTimer(BLUE_TIMER, BLUE_TURN_TIME);
                    break;

                case ES_TIMEOUT:
                    nextState = MoveForward;
                    ServoGrab(1);
                    printf("\n\nSERVO RELEASE TRIGGER");
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    ES_Timer_StopTimer(BLUE_TIMER);
                    break;
            }
            break;
        case DropBlock:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(BLUE_TIMER, BLUE_TURN_TIME);
                    break;

                case ES_TIMEOUT:
                    nextState = MoveForward;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(BLUE_TIMER);
                    break;
            }
            break;

        case MoveForward:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(STRAIGHT_SPEED);
                    RightMotor_SetSpeed(STRAIGHT_SPEED);
                    ES_Timer_InitTimer(BLUE_TIMER, DROP_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = MoveBack;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(BLUE_TIMER);
                    break;
            }
            break;

        case MoveBack:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-STRAIGHT_SPEED);
                    RightMotor_SetSpeed(-STRAIGHT_SPEED);
                    ES_Timer_InitTimer(BLUE_TIMER, BACK_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = TurnAlign;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(BLUE_TIMER);
                    break;
            }
            break;

        case TurnAlign:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-TURN_SPEED);
                    RightMotor_SetSpeed(TURN_SPEED);
                    ES_Timer_InitTimer(BLUE_TIMER, BACK_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = ForwardPastLine;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(BLUE_TIMER);
                    break;
            }
            break;

        case ForwardPastLine:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(STRAIGHT_SPEED);
                    RightMotor_SetSpeed(STRAIGHT_SPEED);
                    ES_Timer_InitTimer(BLUE_TIMER, FORWARD_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = AlignCenter;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(BLUE_TIMER);
                    break;
            }
            break;

        case AlignCenter:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LeftMotor_SetSpeed(-STRAIGHT_SPEED);
                    RightMotor_SetSpeed(-STRAIGHT_SPEED);
                    break;

                case IR_LEFT_ON_LINE:
                    LeftMotor_SetSpeed(0);
                    nextState = AlignLeftWaiting;
                    makeTransition = TRUE;
                    break;

                case IR_RIGHT_ON_LINE:
                    RightMotor_SetSpeed(0);
                    nextState = AlignRightWaiting;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case AlignLeftWaiting:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    break;

                case IR_RIGHT_ON_LINE:
                    RightMotor_SetSpeed(0);
                    returnEvent.EventType = BLUE_FLOW_DONE;
                    return returnEvent;
                    break;

                case ES_EXIT:
                    break;
            }
            break;

        case AlignRightWaiting:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    break;

                case IR_LEFT_ON_LINE:
                    LeftMotor_SetSpeed(0);
                    returnEvent.EventType = BLUE_FLOW_DONE;
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
                    ES_Timer_InitTimer(BLUE_TIMER, REFORWARD_DELAY);
                    break;

                case ES_TIMEOUT:
                    LeftMotor_SetSpeed(0);
                    RightMotor_SetSpeed(0);
                    nextState = AlignCenter;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    ES_Timer_StopTimer(BLUE_TIMER);
                    break;
            }
            break;

        default:
            break;
    }

    if (makeTransition == TRUE) {
        RunBlueFlowSubHSM(EXIT_EVENT);
        CurrentState = nextState;
        printf("Transitioning to %s\n", StateNames[CurrentState]);
        RunBlueFlowSubHSM(ENTRY_EVENT);
    }

    ES_Tail();
    return ThisEvent;
}
