#include "ColorEventChecker.h"
#include "ColorSensor.h"
#include "ES_Events.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TemplateHSM.h"
#include <stdio.h>
#include "BOARD.h"

#define DETECTION_COUNT 3
#define NO_BLOCK_THRESH 9000

#define RED_THRESH_MAX 4000
#define BLUE_THRESH_MAX 5000
#define GREEN_THRESH_MAX 4000

static ES_EventTyp_t lastEvent = COLOR_NOT_DETECTED;
static uint8_t confirmCounter = 0;
static uint8_t filterState = 0; // 0: RED, 1: BLUE, 2: GREEN
static uint16_t redPeriod = 0;
static uint16_t bluePeriod = 0;
static uint16_t greenPeriod = 0;

uint8_t CheckColorEvent(void) {
    ES_Event thisEvent;
    ES_EventTyp_t curEvent = lastEvent;
    uint8_t returnVal = FALSE;

    switch (filterState) {
        case 0:
            ColorSensor_SetFilter(COLOR_FILTER_RED);
            for (volatile int i = 0; i < 10000; i++) asm("nop");
            redPeriod = ColorSensor_GetPeriod();
//            printf("Red Filter Period: %u\n", redPeriod);
            filterState = 1;
            break;
        case 1:
            ColorSensor_SetFilter(COLOR_FILTER_BLUE);
            for (volatile int i = 0; i < 10000; i++) asm("nop");
            bluePeriod = ColorSensor_GetPeriod();
//            printf("Blue Filter Period: %u\n", bluePeriod);
            filterState = 2;
            break;
        case 2:
            ColorSensor_SetFilter(COLOR_FILTER_GREEN);
            for (volatile int i = 0; i < 10000; i++) asm("nop");
            greenPeriod = ColorSensor_GetPeriod();
//            printf("Green Filter Period: %u\n", greenPeriod);
            filterState = 0;
            break;
    }

    // Color classification logic
    if (redPeriod > NO_BLOCK_THRESH && bluePeriod > NO_BLOCK_THRESH && greenPeriod > NO_BLOCK_THRESH) {
        curEvent = COLOR_NOT_DETECTED;

    } else if (redPeriod < RED_THRESH_MAX &&
               (bluePeriod - redPeriod) > 2000 &&
               (greenPeriod - redPeriod) > 2000) {
        curEvent = COLOR_DETECTED_RED;

    } else if (bluePeriod < BLUE_THRESH_MAX &&
               (redPeriod - bluePeriod) > 2000 &&
               (greenPeriod - bluePeriod) > 1500) {
        curEvent = COLOR_DETECTED_BLUE;

    } else if (greenPeriod < GREEN_THRESH_MAX &&
               (redPeriod - greenPeriod) > 800 &&
               (bluePeriod - greenPeriod) > 500) {
        curEvent = COLOR_DETECTED_GREEN;

    } else {
        curEvent = COLOR_NOT_DETECTED;
    }

    // Event posting
    if (curEvent != lastEvent) {
        if (++confirmCounter >= DETECTION_COUNT) {
            thisEvent.EventType = curEvent;
            thisEvent.EventParam = (curEvent == COLOR_DETECTED_RED) ? redPeriod :
                                   (curEvent == COLOR_DETECTED_BLUE) ? bluePeriod :
                                   (curEvent == COLOR_DETECTED_GREEN) ? greenPeriod : 0;

            lastEvent = curEvent;
            confirmCounter = 0;

            printf("\nPosting Event: %s | R:%u B:%u G:%u\r\n",
                   EventNames[thisEvent.EventType], redPeriod, bluePeriod, greenPeriod);

            PostHSM(thisEvent);
            returnVal = TRUE;
        }
    } else {
        confirmCounter = 0;
    }

    return returnVal;
}
