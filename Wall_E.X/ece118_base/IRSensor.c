#include "IRSensor.h"
#include "BOARD.h"

#define IR_LEFT_TRIS  TRISEbits.TRISE7
#define IR_LEFT_PIN   PORTEbits.RE7

//#define IR_RIGHT_TRIS TRISEbits.TRISE6
//#define IR_RIGHT_PIN  PORTEbits.RE6

#define IR_RIGHT_TRIS TRISEbits.TRISE5
#define IR_RIGHT_PIN  PORTEbits.RE5

void IRSensor_Init(void) {
    IR_LEFT_TRIS = 1;    // Set RE7 as input
    IR_RIGHT_TRIS = 1;   // Set RE6 as input
}

uint8_t IRSensor_ReadLeft(void) {
    return IR_LEFT_PIN;  // 0 = line detected
}

uint8_t IRSensor_ReadRight(void) {
    return IR_RIGHT_PIN; // 0 = line detected
}

