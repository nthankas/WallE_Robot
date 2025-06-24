/* CenterSubHSM.h */
#ifndef CENTER_SUB_HSM_H
#define CENTER_SUB_HSM_H
#include "ES_Configure.h"
uint8_t InitCenterSubHSM(void);
ES_Event RunCenterSubHSM(ES_Event ThisEvent);
ES_EventTyp_t CenterSubHSM_GetDetectedColor(void);
#endif

