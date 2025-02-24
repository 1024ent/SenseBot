/**
 * @file main.cpp
 * @brief main ESP32 Mainboard
 * @copyright UMPSA ROBOTICS
 * @licenseLoo Hui Kie [ELPROG]
 */
#include <Arduino.h>
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "PS4Controller.h"
#include "thread_manager.h"
#include "input_config.h"
#include "output_config.h"
#include "std_movement.h"
#include "mecanum_movement.h"
#include "tb6612.h"

void setup() 
{
  Serial.begin(115200);

  init_input_instances();
  init_output_instances();

  thread_manager();
}

void loop() 
{

}

// Mecanum Wheel Movement Function
void mecanum_move_fwd(int speed){

}

void mecanum_move_rev(int speed){

}

void mecanum_shift_left(int speed){
  
}

void mecanum_shift_right(int speed){
  
}

void mecanum_turn_left(int speed){

}

void mecanum_turn_right(int speed){

}

void mecanum_left_fwd(int speed){
  
}

void mecanum_right_fwd(int speed){

}

void mecanum_left_rev(int speed){

}

void mecanum_right_rev(int speed){

}

void mecanum_sharp_right_turn(int speed){
  
}

void mecanum_sharp_left_turn(int speed){

}
