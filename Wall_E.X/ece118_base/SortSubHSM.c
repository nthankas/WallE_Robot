#include <stdio.h>               // Required for printf
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "TemplateHSM.h"
//#include "GrabSubHSM.h"
#include "SortSubHSM.h"
#include "RedFlowSubHSM.h"
#include "BlueFlowSubHSM.h"
#include "Actuators.h"

#define SPEED 80
//#define TURN_SPEED 60

#define SORT_TIMER 14
#define REFORWARD_DELAY 500


typedef enum {
    InitPSortSubState,
    RedState,
    BlueState,
            GreenState,
            NoColor,
} SortSubHSMState_t;

static const char *StateNames[] = {
    "InitPSortSubState",
    "RedState",
    "BlueState",
    "GreenState",
    "NoColor",
};

static SortSubHSMState_t CurrentState = InitPSortSubState;
static uint8_t MyPriority;

uint8_t InitSortSubHSM(uint8_t Priority)
{
    MyPriority = Priority;
    CurrentState = InitPSortSubState;
    printf("InitSortSubHSM: Setting initial state to %s\n", StateNames[CurrentState]);

    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        printf("InitSortSubHSM: Posted INIT_EVENT to HSM\n");
        return TRUE;
    } else {
        printf("InitSortSubHSM: Failed to post INIT_EVENT\n");
        return FALSE;
    }
}

uint8_t PostSortSubHSM(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

ES_Event RunSortSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    SortSubHSMState_t nextState;
    ES_Event returnEvent;

    ES_Tattle();
    printf("RunHSM(%s[%s,%X]);\n", StateNames[CurrentState],
           EventNames[ThisEvent.EventType], ThisEvent.EventParam);

    switch (CurrentState) {
        case InitPSortSubState:
            if (ThisEvent.EventType == ES_INIT) {
                printf("RunSortSubHSM: Initializing SortSubHSM\n");
                
                ES_EventTyp_t color = GetDetectedColor();
                if (color == COLOR_DETECTED_RED) {
                    InitRedFlowSubHSM();
                    nextState = RedState;
                } else if (color == COLOR_DETECTED_BLUE) {
                    InitBlueFlowSubHSM();
                    nextState = BlueState;
                }
                makeTransition = TRUE;
            }
            break;

        case RedState:
            returnEvent = RunRedFlowSubHSM(ThisEvent);
            if (returnEvent.EventType == RED_FLOW_DONE) {
                printf("SortSubHSM: RED_FLOW_DONE -> returning SORT_COMPLETE to TemplateHSM\n");
                ES_Event done = { .EventType = SORT_COMPLETE };
                return done;
            }
            break;

        case BlueState:
            returnEvent = RunBlueFlowSubHSM(ThisEvent);
            if (returnEvent.EventType == BLUE_FLOW_DONE) {
                printf("SortSubHSM: BLUE_FLOW_DONE -> returning SORT_COMPLETE to TemplateHSM\n");
                ES_Event done = { .EventType = SORT_COMPLETE };
                return done;
            }
            break;

        default:
            printf("RunSortSubHSM: Unknown state encountered!\n");
            
            break;
    }

    if (makeTransition) {
        RunSortSubHSM(EXIT_EVENT);
        CurrentState = nextState;
        RunSortSubHSM(ENTRY_EVENT);
    }


    ES_Tail();
    return ThisEvent;
}
