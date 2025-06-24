/* RightSubHSM.h */
#ifndef RIGHT_SUB_HSM_H
#define RIGHT_SUB_HSM_H
#include "ES_Configure.h"
uint8_t InitRightSubHSM(void);
ES_Event RunRightSubHSM(ES_Event ThisEvent);
ES_EventTyp_t RightSubHSM_GetDetectedColor(void);
#endif

