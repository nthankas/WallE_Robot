/* SortSubHSM.h */
#ifndef SORT_SUB_HSM_H
#define SORT_SUB_HSM_H
#include "ES_Configure.h"
uint8_t InitSortSubHSM(uint8_t Priority);
uint8_t PostSortSubHSM(ES_Event ThisEvent);
ES_Event RunSortSubHSM(ES_Event ThisEvent);
#endif