#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include <xc.h>
#include <stdint.h>

void IRSensor_Init(void);
uint8_t IRSensor_ReadLeft(void);   // RE7
uint8_t IRSensor_ReadRight(void);  // RE6

#endif
