//======================= PingSensor.h =======================
#ifndef PING_SENSOR_H
#define PING_SENSOR_H

#include <xc.h>
#include <stdint.h>

int PingSensor_Init(void);
void PingSensor_Trigger(void);
unsigned int PingSensor_GetDistance(void);

#endif
