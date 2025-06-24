#include "IRSensor.h"
#include "ES_Events.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TemplateHSM.h"
#include <stdio.h>
#include "BOARD.h"

#define DETECTED_LINE 1

uint8_t CheckIREvents(void) {
    static uint8_t lastLeft = 1;
    static uint8_t lastRight = 1;
    uint8_t returnVal = FALSE;
    ES_Event thisEvent;

    uint8_t currentLeft = IRSensor_ReadLeft();
    uint8_t currentRight = IRSensor_ReadRight();

    if (currentLeft != lastLeft) {
        thisEvent.EventType = (currentLeft == DETECTED_LINE) ? IR_LEFT_ON_LINE : IR_LEFT_OFF_LINE;
        thisEvent.EventParam = (currentLeft == DETECTED_LINE) ? 1 : 0;
//        printf("Posting Event: %s with Param: %u\r\n",
//        EventNames[thisEvent.EventType], thisEvent.EventParam);
////        PostIRService(thisEvent);
        PostHSM(thisEvent);
        lastLeft = currentLeft;
        returnVal = TRUE;
    }

    if (currentRight != lastRight) {
        thisEvent.EventType = (currentRight == DETECTED_LINE) ? IR_RIGHT_ON_LINE : IR_RIGHT_OFF_LINE;
        thisEvent.EventParam = (currentRight == DETECTED_LINE) ? 1 : 0;
//        printf("Posting Event: %s with Param: %u\r\n",
//        EventNames[thisEvent.EventType], thisEvent.EventParam);
//        PostIRService(thisEvent);
        PostHSM(thisEvent);
        lastRight = currentRight;
        returnVal = TRUE;
    }

    return returnVal;
}
