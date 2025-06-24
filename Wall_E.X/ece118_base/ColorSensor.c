#include "ColorSensor.h"
#include <xc.h>
#include "BOARD.h"
#include <sys/attribs.h>
#include <stdio.h>
#include "IO_Ports.h"

#define PBCLK 80000000U
#define PRESCALER 64
#define SAMPLE_INTERVAL 333

#define S0_MASK PIN4
#define S1_MASK PIN5
#define S2_MASK PIN7
#define S3_MASK PIN8

#define OUT_PORT PORTY
#define OUT_MASK PIN6


static unsigned short colorPeriod = 0;

static unsigned short risingEdge;
static unsigned short nextEdge;

int ColorSensor_Init(void) {

//    T3CON = 0x0;
//    T3CONbits.TCKPS = 0b110;
//    PR3 = 0xFFFF;
//    TMR3 = 0;
//    T3CONbits.ON = 1;
    
    

    IC3CON = 0;
    IC3CONbits.ICTMR = 0;
    IC3CONbits.ICI = 0;
    IC3CONbits.ICM = 0b010;   // Capture only falling edge

    IPC3bits.IC3IP = 4;       // Priority
    IPC3bits.IC3IS = 0;       // Subpriority
    IFS0bits.IC3IF = 0;       // Clear interrupt flag
    IEC0bits.IC3IE = 1;       // Enable interrupt
    IC3CONbits.ON = 1;

    IO_PortsSetPortOutputs(PORTV, S0_MASK | S1_MASK | S2_MASK | S3_MASK);
    IO_PortsSetPortInputs(OUT_PORT, OUT_MASK);

    IO_PortsClearPortBits(PORTV, S0_MASK);
    IO_PortsSetPortBits(PORTV, S1_MASK);  // Set to 1
    
    ColorSensor_SetFilter(COLOR_FILTER_RED);

    return SUCCESS;
}

unsigned short ColorSensor_GetPeriod(void) {
    return colorPeriod;
}

void ColorSensor_SetFilter(uint8_t filter) {
    switch (filter) {
        case COLOR_FILTER_RED:
            IO_PortsClearPortBits(PORTV, S2_MASK | S3_MASK);
            break;
        case COLOR_FILTER_BLUE:
            IO_PortsClearPortBits(PORTV, S2_MASK);
            IO_PortsSetPortBits(PORTV, S3_MASK);
            break;
        case COLOR_FILTER_CLEAR:
            IO_PortsSetPortBits(PORTV, S2_MASK);
            IO_PortsClearPortBits(PORTV, S3_MASK);
            break;
        case COLOR_FILTER_GREEN:
            IO_PortsSetPortBits(PORTV, S2_MASK | S3_MASK);
            break;
    }
}

void __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4AUTO) IC3InterruptHandler(void) {
    IFS0bits.IC3IF = 0;  // Clear flag first

    static unsigned short lastEdge = 0;
    unsigned short thisEdge;

    // Flush all pending captures
    while (IC3CONbits.ICBNE) {
        thisEdge = IC3BUF & 0xFFFF;

        if (thisEdge >= lastEdge) {
            colorPeriod = thisEdge - lastEdge;
        } else {
            colorPeriod = (0xFFFF - lastEdge + thisEdge + 1);
        }
        lastEdge = thisEdge;
    }
}
