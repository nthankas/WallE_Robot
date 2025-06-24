#include "PingSensor.h"
#include <xc.h>
#include <sys/attribs.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "BOARD.h"
#include "ES_Events.h"
#include "ES_Timers.h"
#include "ES_Configure.h"



#define TRIG_LAT LATDbits.LATD5
#define TRIG_TRIS TRISDbits.TRISD5
#define ECHO_PORT PORTDbits.RD9
#define ECHO_TRIS TRISDbits.TRISD9

static unsigned int risingEdge;
static unsigned int fallingEdge;
static unsigned int timeDiff;
unsigned int dist;

int PingSensor_Init(void) {
    TRIG_TRIS = 0;
    TRIG_LAT = 0;
    ECHO_TRIS = 1;

    T3CON = 0;
    T3CONbits.TCKPS = 0b011; // 1:8
    TMR3 = 0;
    PR3 = 0xFFFF;
    T3CONbits.ON = 1;

    IC2CON = 0;
    IC2CONbits.ICTMR = 0;
    IC2CONbits.ICM = 0b001;
    IPC2bits.IC2IP = 5;
    IFS0bits.IC2IF = 0;
    IEC0bits.IC2IE = 1;
    IC2CONbits.ON = 1;

    return SUCCESS;
}

void PingSensor_Trigger(void) {
    TRIG_LAT = 1;

    // 10?s delay at 80MHz = 800 cycles. Each `nop` = 1 cycle
    for (volatile int i = 0; i < 1600; i++) {
        asm("nop");
    }

    TRIG_LAT = 0;
}

unsigned int PingSensor_GetDistance(void) {
    return dist;
}

void __ISR(_INPUT_CAPTURE_2_VECTOR, IPL5AUTO) IC2InterruptHandler(void) {
    if (PORTDbits.RD9 == 1) {  // Rising edge
        risingEdge = (0xFFFF & IC2BUF);  
    }
    if (PORTDbits.RD9 == 0) {  // Falling edge 
        fallingEdge = (0xFFFF & IC2BUF);  
        timeDiff = fallingEdge - risingEdge;  // Compute pulse width
        dist = ((343 * 2 * timeDiff) / (20000));  // Approx. distance in cm
    }
    IFS0bits.IC2IF = 0;
}