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
void mecanum_stp();                         // Mecanum Wheel Stop
void mecanum_move_fwd(int speed);           // Mecanum Wheel Move Foward
void mecanum_move_rev(int speed);           // Mecanum Wheel Reverse
void mecanum_shift_left(int speed);         // Mecanum Wheel Shift to the Left
void mecanum_shift_right(int speed);        // Mecanum Wheel Shift to the Right
void mecanum_fwd_left(int speed);         // Mecanum Wheel Move Forward Left Diagonally
void mecanum_fwd_right(int speed);        // Mecanum Wheel Move Forward Right Diagonally
void mecanum_rev_left(int speed);         // Mecanum Wheel Move Reverse Left Diagonally
void mecanum_rev_right(int speed);        // Mecanum Wheel Move Reverse Right Diagonally
void mecanum_rotate_cw(int speed);         // Mecanum Wheel Rotate Clockwise
void mecanum_rotate_ccw(int speed);       // Mecanum Wheel Rotate Counter Clockwise
void mecanum_turn_left(int speed, float offset);         // Mecanum Wheel Turn Left
void mecanum_turn_right(int speed, float offset);        // Mecanum Wheel Turn Right
void mecanum_turn_front_cw(int speed);         // Mecanum Wheel Turn Rear Left
void mecanum_turn_front_ccw(int speed);        // Mecanum Wheel Turn Rear Right

#endif 