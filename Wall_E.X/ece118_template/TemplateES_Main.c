#include "BOARD.h"
#include <xc.h>
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "PingSensor.h"
#include "ColorSensor.h"
#include "IRSensor.h"
#include "Actuators.h"
#include "TemplateHSM.h"

void main(void)
{
    ES_Return_t ErrorType;

    BOARD_Init();
    printf("WALL-E Project Starting...\r\n");

    // Initialize critical hardware
    Motor_Init();
    Servo_Init();
//    PingSensor_Init();     // Uses IC2 + Timer3
    ColorSensor_Init();    // Uses IC3 + Timer3
    IRSensor_Init();       // Uses RE6/RE7 as digital inputs

    // Initialize the Events and Services Framework
    ErrorType = ES_Initialize();
    if (ErrorType == Success) {
        ErrorType = ES_Run();  // Start state machine execution (blocking)
    }

    // If the framework exits (which it shouldn't), report the error
    switch (ErrorType) {
        case FailedPointer:
            printf("Framework Error: NULL pointer\r\n");
            break;
        case FailedInit:
            printf("Framework Error: Initialization failed\r\n");
            break;
        default:
            printf("Framework Error: Code %d\r\n", ErrorType);
            break;
    }

    for (;;); // trap CPU if framework exits
}
