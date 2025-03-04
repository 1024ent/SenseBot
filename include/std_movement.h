/**
 * @file stf_movement.h
 * @brief Managing Standard Wheel Movement
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#ifndef __STD_MOVEMENT_H__
#define __STD_MOVEMENT_H__

// Standard Wheel Movement Function Declaration
void std_stp();            // Standard Wheel Brake
void std_fwd(int speed);            // Standard Wheel Move Foward 
void std_rev(int speed);            // Standard Wheel Reverse
void std_left_fwd(int speed);       // Standard Wheel Move Forward Left
void std_right_fwd(int speed);      // Standard Wheel Move Forward Right
void std_left_rev(int speed);       // Standard Wheel Reverse Left
void std_right_rev(int speed);      // Standard Wheel Reverse Right

#endif 