//======================= PingService.c =======================
#include "PingService.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "PingSensor.h"
#include "ES_TimerService.h"
#include "ES_Timers.h"
#include <stdio.h>
#include <BOARD.h>

#define PING_TIMER 0

static uint8_t MyPriority;

uint8_t InitPingService(uint8_t Priority) {
    MyPriority = Priority;
    PingSensor_Init();
    ES_Timer_InitTimer(PING_TIMER, 60);

    ES_Event ThisEvent = { ES_INIT, 0 };
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }

}

uint8_t PostPingService(ES_Event ThisEvent) {
    
    return ES_PostToService(MyPriority, ThisEvent);
}

ES_Event RunPingService(ES_Event ThisEvent) {
    ES_Event ReturnEvent = { ES_NO_EVENT, 0 };

    switch (ThisEvent.EventType) {
        case ES_TIMEOUT:
            if (ThisEvent.EventParam == PING_TIMER) {
                PingSensor_Trigger();
                CheckDist();
                ES_Timer_InitTimer(PING_TIMER, 60);
            }
            break;

        case ES_INIT:
            break;
    }

    return ReturnEvent;
}

