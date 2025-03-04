/**
 * @file input_config.h
 * @brief Line Following Mechanism
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#include <Arduino.h>
#include "input_config.h"
#include "mecanum_movement.h"
#include "std_movement.h"
#include "line_following.h"

void line_following_std()
{
    // Perform line following
    int D1 = digitalRead(LINE_D1);
    int D2 = digitalRead(LINE_D2);
    int D3 = digitalRead(LINE_D3);
    int D4 = digitalRead(LINE_D4);
    int D5 = digitalRead(LINE_D5);

    for(;;){
        if (D1==0 && D2==0 && D3==1 && D4==0 && D5==0) {
            //robot move forward
            std_fwd(HIGH_SPEED);
          }
          else if (D1==0 && D2==1 && D3==0 && D4==0 && D5==0) {
            //move to left
            std_left_fwd(HIGH_SPEED);
          }
          else if (D1==1 && D2==0 && D3==0 && D4==0 && D5==0) {
            //robot slowing down, move more to left
            std_left_fwd(MID_SPEED);
          }
          else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==0) {
            //move to right
            std_right_fwd(HIGH_SPEED);
          }
          else if (D1==0 && D2==0 && D3==0 && D4==0 && D5==1) {
            //robot slowing down, move more to right
            std_right_fwd(MID_SPEED);
          }
          else {
            // stop robot
            std_stp();
          }
    }
}
void line_following_mecanum()
{
    // Perform line following
    int D1 = digitalRead(LINE_D1);
    int D2 = digitalRead(LINE_D2);
    int D3 = digitalRead(LINE_D3);
    int D4 = digitalRead(LINE_D4);
    int D5 = digitalRead(LINE_D5);

    for(;;){
        if (D1==0 && D2==0 && D3==1 && D4==0 && D5==0) {
            //robot move forward
            mecanum_move_fwd(HIGH_SPEED);
          }
          else if (D1==0 && D2==1 && D3==0 && D4==0 && D5==0) {
            //move to left
            mecanum_left_fwd(HIGH_SPEED);
          }
          else if (D1==1 && D2==0 && D3==0 && D4==0 && D5==0) {
            //robot slowing down, move more to left
            mecanum_left_fwd(MID_SPEED);
          }
          else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==0) {
            //move to right
            mecanum_right_fwd(HIGH_SPEED);
          }
          else if (D1==0 && D2==0 && D3==0 && D4==0 && D5==1) {
            //robot slowing down, move more to right
            mecanum_right_fwd(MID_SPEED);
          }
          else {
            // stop robot
            mecanum_stp();
          }
    }
}