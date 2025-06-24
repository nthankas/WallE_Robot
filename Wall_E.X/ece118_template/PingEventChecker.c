//======================= PingEventChecker.c =======================
#include "PingEventChecker.h"
#include "PingSensor.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ES_Events.h"
#include "BOARD.h"
#include "TemplateHSM.h"
#include <stdio.h>

#define CLOSE_THRESHOLD      60     // Under ~6cm
#define DETECT_THRESHOLD_LO 300     // Enter OBJDETECT below ~30cm // was 400
#define DETECT_THRESHOLD_HI 730     // Stay in OBJDETECT up to ~80cm
#define MAX_VALID_DISTANCE   900   // Ignore jumps beyond ~2.5m
#define CLOSE_CONFIRM_COUNT  3      // was 5
#define DETECT_CONFIRM_COUNT 1
#define FAR_CONFIRM_COUNT    3

uint8_t CheckDist(void) {
    static ES_EventTyp_t lastEvent = PING_FAR;
    static ES_EventTyp_t postedEvent = PING_FAR;
    static uint8_t closeCounter = 0;
    static uint8_t detectCounter = 0;
    static uint8_t farCounter = 0;
    static uint8_t initialized = FALSE;
    static unsigned int lastDist = 0;

    ES_Event thisEvent;
    unsigned short pingDist = PingSensor_GetDistance();
//    printf("Ping Distance: %u \r\n", pingDist);

    // Basic low-pass filter
    if (pingDist < MAX_VALID_DISTANCE) {
        lastDist = (lastDist * 9 + pingDist) / 10;
    }

    ES_EventTyp_t proposedEvent = lastEvent;

    switch (lastEvent) {
        case PING_CLOSE:
            if (lastDist > CLOSE_THRESHOLD + 10) {
                proposedEvent = PING_OBJDETECT;
            }
            break;
        case PING_OBJDETECT:
            if (lastDist < CLOSE_THRESHOLD) {
                proposedEvent = PING_CLOSE;
            } else if (lastDist > DETECT_THRESHOLD_HI) {
                proposedEvent = PING_FAR;
            }
            break;
        case PING_FAR:
        default:
            if (lastDist < DETECT_THRESHOLD_HI) {
                proposedEvent = PING_OBJDETECT;
            }
            break;
    }

    if (proposedEvent != lastEvent) {
        switch (proposedEvent) {
            case PING_CLOSE:
                if (++closeCounter >= CLOSE_CONFIRM_COUNT) {
                    lastEvent = PING_CLOSE;
                    closeCounter = detectCounter = farCounter = 0;
                }
                break;
            case PING_OBJDETECT:
                if (++detectCounter >= DETECT_CONFIRM_COUNT) {
                    lastEvent = PING_OBJDETECT;
                    closeCounter = detectCounter = farCounter = 0;
                }
                break;
            case PING_FAR:
                if (++farCounter >= FAR_CONFIRM_COUNT) {
                    lastEvent = PING_FAR;
                    closeCounter = detectCounter = farCounter = 0;
                }
                break;
        }
    } else {
        closeCounter = detectCounter = farCounter = 0;
    }

    if (!initialized || lastEvent != postedEvent) {
        thisEvent.EventType = lastEvent;
        thisEvent.EventParam = lastDist;
        postedEvent = lastEvent;
        initialized = TRUE;
//        printf("Posting Event: %s with Param: %u\r\n",
//               EventNames[thisEvent.EventType], thisEvent.EventParam);
//        PostHSM(thisEvent);
        return TRUE;
    }

    return FALSE;
}
