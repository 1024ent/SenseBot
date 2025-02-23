/**
 * @file tb6612.cpp
 * @brief TB6612 Motor Driver Library
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#include <Arduino.h>
#include "tb6612.h"

Motor::Motor(int In1pin, int In2pin, int PWMpin, int offset, int STBYpin){
    In1 = In1pin;
    In2 = In2pin;
    PWM = PWMpin;
    Standby = STBYpin;
    Offset = offset;

    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(PWM, OUTPUT);
    pinMode(Standby, OUTPUT);
};

// Motor Driver Function
void FL_fwd(int speed){
    digitalWrite(LEFT_AIN1,1);
    digitalWrite(LEFT_AIN2,0);
    ledcWrite(pwmChannel_left, speed);
}

void FL_rev(int speed){
    digitalWrite(LEFT_AIN1,0);
    digitalWrite(LEFT_AIN2,1);
    ledcWrite(pwmChannel_left, speed);
}

void RL_fwd(int speed){
    digitalWrite(LEFT_BIN1,1);
    digitalWrite(LEFT_BIN2,0);
    ledcWrite(pwmChannel_left, speed);
}

void RL_rev(int speed){
    digitalWrite(LEFT_BIN1,0);
    digitalWrite(LEFT_BIN2,1);
    ledcWrite(pwmChannel_left, speed);
}

void FR_fwd(int speed){
    digitalWrite(RIGHT_AIN1,1);
    digitalWrite(RIGHT_AIN2,0);
    ledcWrite(pwmChannel_right, speed);
}

void FR_rev(int speed){
    digitalWrite(RIGHT_AIN1,0);
    digitalWrite(RIGHT_AIN2,1);
    ledcWrite(pwmChannel_right, speed);
}

void RR_fwd(int speed){
    digitalWrite(RIGHT_BIN1,1);
    digitalWrite(RIGHT_BIN2,0);
    ledcWrite(pwmChannel_right, speed);
}

void RR_rev(int speed){
    digitalWrite(RIGHT_BIN1,0);
    digitalWrite(RIGHT_BIN2,1);
    ledcWrite(pwmChannel_right, speed);
}

void brake(int speed){
    digitalWrite(LEFT_AIN1,1);
    digitalWrite(LEFT_AIN2,1);  
    digitalWrite(LEFT_BIN1,1);
    digitalWrite(LEFT_BIN2,1);
    ledcWrite(pwmChannel_left, speed);  
    digitalWrite(RIGHT_AIN1,1);
    digitalWrite(RIGHT_AIN2,1);
    digitalWrite(RIGHT_BIN1,1);
    digitalWrite(RIGHT_BIN2,1);
    ledcWrite(pwmChannel_right, speed);  
}

