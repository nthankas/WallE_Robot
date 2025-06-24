//======================= ColorService.c =======================
#include "ColorService.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ColorSensor.h"
#include "ColorEventChecker.h"
#include "ES_TimerService.h"
#include "ES_Timers.h"
#include <stdio.h>
#include <BOARD.h>

#define COLOR_TIMER 1  // Make sure this matches ES_Configure.h

static uint8_t MyPriority;

uint8_t InitColorService(uint8_t Priority) {
    MyPriority = Priority;
    ColorSensor_Init();
    ES_Timer_InitTimer(COLOR_TIMER, 60);  // 60ms sampling

    ES_Event ThisEvent = { ES_INIT, 0 };
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

uint8_t PostColorService(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

ES_Event RunColorService(ES_Event ThisEvent) {
    ES_Event ReturnEvent = { ES_NO_EVENT, 0 };

    switch (ThisEvent.EventType) {
        case ES_TIMEOUT:
            if (ThisEvent.EventParam == COLOR_TIMER) {
                CheckColorEvent();
                ES_Timer_InitTimer(COLOR_TIMER, 60);
            }
            break;

        case ES_INIT:
            break;
    }

    return ReturnEvent;
}
