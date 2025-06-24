//======================= ColorService.h =======================
#ifndef COLOR_SERVICE_H
#define COLOR_SERVICE_H

#include "ES_Configure.h"
#include "ES_Framework.h"

uint8_t InitColorService(uint8_t Priority);
uint8_t PostColorService(ES_Event ThisEvent);
ES_Event RunColorService(ES_Event ThisEvent);

#endif