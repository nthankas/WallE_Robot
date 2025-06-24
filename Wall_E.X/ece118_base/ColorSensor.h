//======================= ColorSensor.h =======================
#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <stdint.h>

#define COLOR_FILTER_RED    0
#define COLOR_FILTER_BLUE   1
#define COLOR_FILTER_CLEAR  2
#define COLOR_FILTER_GREEN  3

int ColorSensor_Init(void);
unsigned short ColorSensor_GetPeriod(void);
void ColorSensor_SetFilter(uint8_t filter);

#endif