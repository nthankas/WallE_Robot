/* LeftSubHSM.h */
#ifndef LEFT_SUB_HSM_H
#define LEFT_SUB_HSM_H
#include "ES_Configure.h"
uint8_t InitLeftSubHSM(void);
ES_Event RunLeftSubHSM(ES_Event ThisEvent);
ES_EventTyp_t LeftSubHSM_GetDetectedColor(void);
#endif

