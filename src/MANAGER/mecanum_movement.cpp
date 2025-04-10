/**
 * @file mecanum_movement.cpp
 * @brief Managing thread indicator
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 * @author Al-Imran [ELPROG]
 */

#include <Arduino.h>
#include "output_config.h"
#include "tb6612.h"
#include "mecanum_movement.h"

Motor MFL_Motor = Motor(LEFT_AIN1,LEFT_AIN2,pwmChannel_left,LEFT_PWM,FL_offset,STBY);
Motor MRL_Motor = Motor(LEFT_BIN1,LEFT_BIN2,pwmChannel_left,LEFT_PWM,RL_offset,STBY);
Motor MFR_Motor = Motor(RIGHT_AIN1,RIGHT_AIN2,pwmChannel_right,RIGHT_PWM,FR_offset,STBY);
Motor MRR_Motor = Motor(RIGHT_BIN1,RIGHT_BIN2,pwmChannel_right,RIGHT_PWM,RR_offset,STBY);

// Mecanum Wheel Movement Function
void mecanum_stp(){
    MFL_Motor.brake();
    MRL_Motor.brake();
    MFR_Motor.brake();
    MRR_Motor.brake(); 
}

void mecanum_move_fwd(int speed){
    MFL_Motor.drive(speed);
    MRL_Motor.drive(speed);
    MFR_Motor.drive(speed);
    MRR_Motor.drive(speed);
}

void mecanum_move_rev(int speed){
    MFL_Motor.drive(-speed);
    MRL_Motor.drive(-speed);
    MFR_Motor.drive(-speed);
    MRR_Motor.drive(-speed);
}

void mecanum_shift_right(int speed){
    MFL_Motor.drive(speed);  
    MRL_Motor.drive(-speed); 
    MFR_Motor.drive(-speed);  
    MRR_Motor.drive(speed); 
}

void mecanum_shift_left(int speed){
    MFL_Motor.drive(-speed); 
    MRL_Motor.drive(speed);  
    MFR_Motor.drive(speed); 
    MRR_Motor.drive(-speed);  
}

void mecanum_fwd_left(int speed){
    MRL_Motor.drive(speed); 
    MFR_Motor.drive(speed); 

}

void mecanum_fwd_right(int speed){
    MFL_Motor.drive(speed);
    MRR_Motor.drive(speed);
}

void mecanum_rev_left(int speed) { 
    MFL_Motor.drive(-speed); 
    MRR_Motor.drive(-speed); 
}

void mecanum_rev_right(int speed) {
    MRL_Motor.drive(-speed); 
    MFR_Motor.drive(-speed); 
}

void mecanum_rotate_cw(int speed) {
    MFL_Motor.drive(speed); 
    MRL_Motor.drive(-speed); 
    MFR_Motor.drive(speed); 
    MRR_Motor.drive(-speed); 
}

void mecanum_rotate_ccw(int speed) {
    MFL_Motor.drive(-speed); 
    MRL_Motor.drive(speed); 
    MFR_Motor.drive(-speed); 
    MRR_Motor.drive(speed); 
}

void mecanum_turn_left(int speed, float offset) {
    MFL_Motor.drive(speed * offset);
    MRL_Motor.drive(speed * offset);
    MFR_Motor.drive(speed);
    MRR_Motor.drive(speed);    
}

void mecanum_turn_right(int speed, float offset) {
    MFL_Motor.drive(speed);
    MRL_Motor.drive(speed);
    MFR_Motor.drive(speed * offset);
    MRR_Motor.drive(speed * offset); 
}
