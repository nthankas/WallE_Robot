
#ifndef ACTUATORS_H
#define	ACTUATORS_H

#include <xc.h>
#include <BOARD.h>
#include "pwm.h"
#include "RC_Servo.h"
#include "AD.h"

// ==========================
// Constants and Definitions
// ==========================
#define MOTOR_MAX_SPEED 100
#define MAX_PWM 1000

// probably not needed
#define SERVO_MIN     1000
#define SERVO_CENTER  1500
#define SERVO_MAX     2000

// ========== Port Defines ==========
// Servo Ports
#define LEFT_SERVO  RC_PORTW07
#define RIGHT_SERVO RC_PORTW08

// Motor Control Pins
#define IN1_TRIS TRISDbits.TRISD7
#define IN1_LAT  LATDbits.LATD7
#define IN2_TRIS TRISDbits.TRISD4
#define IN2_LAT  LATDbits.LATD4
#define IN3_TRIS TRISDbits.TRISD6
#define IN3_LAT  LATDbits.LATD6
#define IN4_TRIS TRISDbits.TRISD11
#define IN4_LAT  LATDbits.LATD11

#define EN_A PWM_PORTY04
#define EN_B PWM_PORTY10

// ==========================
// Function Prototypes
// ==========================

// General
void delay_ms(unsigned int ms);

// Motor
void Motor_Init(void);
char LeftMotor_SetSpeed(char newSpeed);
char RightMotor_SetSpeed(char newSpeed);

// Servo
void Servo_Init(void);
void LeftServo_SetPulse(unsigned int pulseWidth);
void RightServo_SetPulse(unsigned int pulseWidth);
void ServoGrab(unsigned int open);

#endif
