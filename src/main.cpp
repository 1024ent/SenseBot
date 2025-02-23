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

// Standard Wheel Movement Function Declaration
void std_fwd(int speed);                                  // Standard Wheel Move Foward 
void std_rev(int speed);                                  // Standard Wheel Reverse
void std_left_fwd(int speed_1, int speed_);               // Standard Wheel Move Forward Left
void std_right_fwd(int speed_1, int speed_);              // Standard Wheel Move Forward Right
void std_left_rev(int speed_1, int speed_);               // Standard Wheel Reverse Left
void std_right_rev(int speed_1, int speed_);              // Standard Wheel Reverse Right

// Mecanum Wheel Movement Function Declaration
void mecanum_move_fwd(int speed);           // Mecanum Wheel Move Foward
void mecanum_move_rev(int speed);           // Mecanum Wheel Reverse
void mecanum_shift_left(int speed);         // Mecanum Wheel Shift to the Left
void mecanum_shift_right(int speed);        // Mecanum Wheel Shift to the Right
void mecanum_turn_left(int speed);          // Mecanum Wheel Turn to the Left
void mecanum_turn_right(int speed);         // Mecanum Wheel Turn to the Right
void mecanum_left_fwd(int speed);           // Mecanum Wheel Move to the Left
void mecanum_right_fwd(int speed);          // Mecanum Wheel Move to the Right
void mecanum_left_rev(int speed);           // Mecanum Wheel Reverse Left
void mecanum_right_rev(int speed);          // Mecanum Wheel Reverse Right
void mecanum_sharp_right_turn(int speed);   // Mecanum Wheel Move Sharp Right
void mecanum_sharp_left_turn(int speed);    // Mecanum Wheel Move Sharp Left

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

// // Standard Wheel Movement Function
// void std_fwd(int speed){
//   FL_fwd(speed);
//   RL_fwd(speed);
//   FR_fwd(speed);
//   RR_fwd(speed);
// }

// void std_rev(int speed){
//   FL_rev(speed);
//   RL_rev(speed);
//   FR_rev(speed);
//   RR_rev(speed);
// }

void std_left_fwd(int speed_1, int speed_2){

}

void std_right_fwd(int speed_1, int speed_){

}

void std_left_rev(int speed_1, int speed_){

}

void std_right_rev(int speed_1, int speed_){

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
