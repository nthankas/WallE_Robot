#include <xc.h>
#include <BOARD.h>
#include "Actuators.h"

/*******************************************************************************
 * DELAY FUNCTION                                                              *
 ******************************************************************************/
void delay_ms(unsigned int ms) {
    for (unsigned int i = 0; i < ms * 4000; i++) {
        asm("nop");
    }
}

/*******************************************************************************
 * MOTOR FUNCTIONS                                                             *
 ******************************************************************************/
void Motor_Init(void) {
    PWM_Init();
    PWM_SetFrequency(PWM_1KHZ);
    PWM_AddPins(EN_A | EN_B);

    IN1_TRIS = 0;
    IN2_TRIS = 0;
    IN3_TRIS = 0;
    IN4_TRIS = 0;

    IN1_LAT = 0;
    IN2_LAT = 0;
    IN3_LAT = 0;
    IN4_LAT = 0;
}

char LeftMotor_SetSpeed(char newSpeed) {
    if (newSpeed < -MOTOR_MAX_SPEED || newSpeed > MOTOR_MAX_SPEED) {
        return ERROR;
    }

    if (newSpeed == 0) {
        IN3_LAT = 0;
        IN4_LAT = 1;
        PWM_SetDutyCycle(EN_B, 0);
        return SUCCESS;
    }

    if (newSpeed < 0) {
        IN3_LAT = 1;
        IN4_LAT = 0;
        newSpeed = -newSpeed;
    } else {
        IN3_LAT = 0;
        IN4_LAT = 1;
    }

    return PWM_SetDutyCycle(EN_B, newSpeed * (MAX_PWM / MOTOR_MAX_SPEED));
}

char RightMotor_SetSpeed(char newSpeed) {
    if (newSpeed < -MOTOR_MAX_SPEED || newSpeed > MOTOR_MAX_SPEED) {
        return ERROR;
    }

    if (newSpeed == 0) {
        IN1_LAT = 1;
        IN2_LAT = 0;
        PWM_SetDutyCycle(EN_A, 0);
        return SUCCESS;
    }

    if (newSpeed < 0) {
        IN1_LAT = 1;
        IN2_LAT = 0;
        newSpeed = -newSpeed;
    } else {
        IN1_LAT = 0;
        IN2_LAT = 1;
    }

    return PWM_SetDutyCycle(EN_A, newSpeed * (MAX_PWM / MOTOR_MAX_SPEED));
}

/*******************************************************************************
 * SERVO FUNCTIONS                                                             *
 ******************************************************************************/
void Servo_Init(void) {
    RC_Init();
    RC_AddPins(LEFT_SERVO | RIGHT_SERVO);
}

void LeftServo_SetPulse(unsigned int pulseWidth) {
    if (pulseWidth >= MINPULSE && pulseWidth <= MAXPULSE) {
        RC_SetPulseTime(LEFT_SERVO, pulseWidth);
    }
}

void RightServo_SetPulse(unsigned int pulseWidth) {
    if (pulseWidth >= MINPULSE && pulseWidth <= MAXPULSE) {
        RC_SetPulseTime(RIGHT_SERVO, pulseWidth);
    }
}

void ServoGrab(unsigned int open){
    if(open){ // open servos
        RC_SetPulseTime(LEFT_SERVO, MAXPULSE);
        delay_ms(10);
        RC_SetPulseTime(RIGHT_SERVO, MINPULSE);
        delay_ms(10);
    } else { // close servos
        RC_SetPulseTime(RIGHT_SERVO, MAXPULSE);
        delay_ms(10);
        RC_SetPulseTime(LEFT_SERVO, MINPULSE);
        delay_ms(10);
    }
}

//#define MotorTest
#ifdef MotorTest
int main(void) {
    BOARD_Init();
    Motor_Init();
    Servo_Init();
    
    while(1){
        printf("Left Motor Forward\n");
        LeftMotor_SetSpeed(60);
        delay_ms(500);
        printf("Left Motor Backward\n");
        LeftMotor_SetSpeed(-60);
        delay_ms(500);
        printf("Left Motor Stop\n");
        LeftMotor_SetSpeed(0);
        delay_ms(500);
        
        printf("Right Motor Forward\n");
        RightMotor_SetSpeed(60);
        delay_ms(500);
        printf("Right Motor Backward\n");
        RightMotor_SetSpeed(-60);
        delay_ms(500);
        printf("Right Motor Stop\n");
        RightMotor_SetSpeed(0);
        delay_ms(500);
    }
    
    return 0;
}
#endif

//#define ServoTest
#ifdef ServoTest
int main(void) {
    BOARD_Init();
    Servo_Init();
    
    while(1){
        ServoGrab(1); // open
        delay_ms(500);
        ServoGrab(0); // close
        delay_ms(500);
    }
}
#endif


