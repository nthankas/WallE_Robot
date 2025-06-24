//======================= PingService.h =======================
#ifndef PING_SERVICE_H
#define PING_SERVICE_H

#include "ES_Configure.h"
#include "ES_Events.h"

uint8_t InitPingService(uint8_t Priority);
uint8_t PostPingService(ES_Event ThisEvent);
ES_Event RunPingService(ES_Event ThisEvent);

#endif