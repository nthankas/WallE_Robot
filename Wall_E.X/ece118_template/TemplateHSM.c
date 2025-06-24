#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "TemplateHSM.h"

#include "CenterSubHSM.h"
#include "LeftSubHSM.h"
#include "RightSubHSM.h"
#include "SortSubHSM.h"


typedef enum {
    InitPState,
    CenterState,
    LeftState,
    RightState,
    SortState,
            End,
} HSMState_t;

static const char *StateNames[] = {
    "InitPState",
    "CenterState",
    "LeftState",
    "RightState",
    "SortState",
    "End",
};

static HSMState_t CurrentState = InitPState;
static uint8_t MyPriority;

static uint8_t SortConf;

static ES_EventTyp_t lastDetectedColor = COLOR_NOT_DETECTED;

ES_EventTyp_t GetDetectedColor(void) {
    return lastDetectedColor;
}

void NOP_Delay(unsigned int count) {
    for (volatile unsigned int i = 0; i < count; i++) {
        asm("nop");
    }
}

uint8_t InitHSM(uint8_t Priority)
{
    MyPriority = Priority;
    CurrentState = InitPState;
    //printf("InitHSM: Setting initial state to %s\n", StateNames[CurrentState]);

    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        printf("InitHSM: Posted INIT_EVENT to HSM\n");
        return TRUE;
    } else {
        printf("InitHSM: Failed to post INIT_EVENT\n");
        return FALSE;
    }
}

uint8_t PostHSM(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

ES_Event RunHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    HSMState_t nextState;
    ES_Event returnEvent;

    ES_Tattle();
    //printf("RunHSM(%s[%s,%X]);\n", StateNames[CurrentState],
           //EventNames[ThisEvent.EventType], ThisEvent.EventParam);

    
    static uint8_t stage = 1;

        switch (CurrentState) {
            case InitPState:
                if (ThisEvent.EventType == ES_INIT) {
                    printf("\n\nRunHSM: Initializing HSM\n\n");
                    InitCenterSubHSM();
                  
                    nextState = CenterState;
                    makeTransition = TRUE;
                }
                break;

            case CenterState:
                returnEvent = RunCenterSubHSM(ThisEvent);
                if (returnEvent.EventType == CENTER_DONE) {
                    lastDetectedColor = CenterSubHSM_GetDetectedColor();
                    InitSortSubHSM(MyPriority);
                    nextState = SortState;
                    SortConf = TRUE;
                    
                    makeTransition = TRUE;
                }
                break;


            case LeftState:
                returnEvent = RunLeftSubHSM(ThisEvent);
                if (returnEvent.EventType == LEFT_DONE) {
                    lastDetectedColor = LeftSubHSM_GetDetectedColor();
                    InitSortSubHSM(MyPriority);
                    nextState = SortState;
                    SortConf = TRUE;
                    makeTransition = TRUE;
                }
                break;
//
            case RightState:
                returnEvent = RunRightSubHSM(ThisEvent);
                if (returnEvent.EventType == RIGHT_DONE) {
                    lastDetectedColor = RightSubHSM_GetDetectedColor();
                    InitSortSubHSM(MyPriority);
                    nextState = SortState;
                    SortConf = TRUE;
                    makeTransition = TRUE;
                }
                break;

            case SortState:
                
                returnEvent = RunSortSubHSM(ThisEvent);
                if (((returnEvent.EventType == SORT_COMPLETE) || (lastDetectedColor == COLOR_NOT_DETECTED) || (lastDetectedColor == COLOR_DETECTED_GREEN)) && SortConf == TRUE) {
                    printf("Entering switching stage sort\n");
                    switch (stage) {
                        case 1:
                            InitLeftSubHSM();
                            printf("RunHSM: SHIFTING TO LEFT \n");
                            nextState = LeftState;
                            stage = 2;
                            makeTransition = TRUE;
                            SortConf = FALSE;
                            break;

                        case 2:
                            InitRightSubHSM();
                            printf("RunHSM: SHIFTING TO RIGHT \n");
                            nextState = RightState;
                            stage = 5;
                            makeTransition = TRUE;
                            SortConf = FALSE;
                            break;

                        case 5:
                            printf("RunHSM: Final SORT_COMPLETE ? END\n");
                            returnEvent.EventType = ES_NO_EVENT;
                            nextState = End;
                            makeTransition = TRUE;
                            break;

                        default:
                            printf("RunHSM: Unknown stage in SortState (stage = %d)\n", stage);
                            break;
                    }
                }
                break;
            case End:
                printf("Wall-E Job Completed\n");
                break;

        }

    if (makeTransition) {
        printf("RunHSM: Exiting %s\n", StateNames[CurrentState]);
        RunHSM(EXIT_EVENT);
        CurrentState = nextState;
        printf("RunHSM: Entering %s\n", StateNames[CurrentState]);
        RunHSM(ENTRY_EVENT);
    }

    ES_Tail();
    return ThisEvent;
}
