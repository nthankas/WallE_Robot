#ifndef IR_SERVICE_H
#define IR_SERVICE_H

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ES_Events.h"

uint8_t InitIRService(uint8_t Priority);
uint8_t PostIRService(ES_Event ThisEvent);
ES_Event RunIRService(ES_Event ThisEvent);

#endif // IR_SERVICE_H
