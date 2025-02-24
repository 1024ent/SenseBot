/**
 * @file std_movement.cpp
 * @brief Managing thread indicator
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#include <Arduino.h>
#include "output_config.h"
#include "tb6612.h"

const int offset = 0.5;

Motor FL_Motor = Motor(LEFT_AIN1,LEFT_AIN2,pwmChannel_left,LEFT_PWM,FL_offset,STBY);
Motor RL_Motor = Motor(LEFT_BIN1,LEFT_BIN2,pwmChannel_left,LEFT_PWM,RL_offset,STBY);
Motor FR_Motor = Motor(RIGHT_AIN1,RIGHT_AIN2,pwmChannel_right,RIGHT_PWM,FR_offset,STBY);
Motor RR_Motor = Motor(RIGHT_BIN1,RIGHT_BIN2,pwmChannel_right,RIGHT_PWM,RR_offset,STBY);

// Standard Wheel Movement Function
void std_fwd(int speed){
    FL_Motor.drive(-speed);
    RL_Motor.drive(-speed);
    FR_Motor.drive(speed);
    RR_Motor.drive(speed);
}

void std_rev(int speed){
    FL_Motor.drive(speed);
    RL_Motor.drive(speed);
    FR_Motor.drive(-speed);
    RR_Motor.drive(-speed);
}

void std_left_fwd(int speed){
    FL_Motor.drive(-speed);
    RL_Motor.drive(-speed);
    FR_Motor.drive(speed * offset);
    RR_Motor.drive(speed * offset);    
}

void std_right_fwd(int speed){
    FL_Motor.drive(-speed * offset);
    RL_Motor.drive(-speed * offset);
    FR_Motor.drive(speed);
    RR_Motor.drive(speed);
}

void std_left_rev(int speed){
    FL_Motor.drive(speed * offset);
    RL_Motor.drive(speed * offset);
    FR_Motor.drive(-speed);
    RR_Motor.drive(-speed);
}

void std_right_rev(int speed){
    FL_Motor.drive(speed);
    RL_Motor.drive(speed);
    FR_Motor.drive(-speed * offset);
    RR_Motor.drive(-speed * offset);
}
 