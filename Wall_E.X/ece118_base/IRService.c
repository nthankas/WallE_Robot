//======================= IRService.c =======================
#include "ColorService.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "IRSensor.h"
#include "IREventChecker.h"
#include "ES_TimerService.h"
#include "ES_Timers.h"
#include <stdio.h>
#include <BOARD.h>


#define IR_TIMER 2

static uint8_t MyPriority;


uint8_t InitIRService(uint8_t Priority) {
    IRSensor_Init();
    return TRUE;
}

uint8_t PostIRService(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

ES_Event RunIRService(ES_Event ThisEvent) {
    ES_Event ReturnEvent = { ES_NO_EVENT, 0 };

    switch (ThisEvent.EventType) {
        case ES_TIMEOUT:
            if (ThisEvent.EventParam == IR_TIMER) {
                CheckIREvents();
                ES_Timer_InitTimer(IR_TIMER, 60);
            }
            break;

        case ES_INIT:
            break;
    }

    return ReturnEvent;
}



