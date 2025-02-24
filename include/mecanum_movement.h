/**
 * @file mecanum_movement.h
 * @brief Managing Mecanum Wheel Movement
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#ifndef __MECANUM_MOVEMENT_H__
#define __MECANUM_MOVEMENT_H__

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

#endif 