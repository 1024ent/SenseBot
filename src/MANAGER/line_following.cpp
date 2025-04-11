/**
 * @file input_config.h
 * @brief Line Following Mechanism
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 * @author Al-Imran [ELPROG]
 * @author Ronald Lee Deng [MECH]
 */

#include <Arduino.h>
#include "input_config.h"
#include "mecanum_movement.h"
#include "std_movement.h"
#include "line_following.h"

void line_following_std(void *pvParameters)
{
  for(;;){
    // Read line sensor values 
    int D1 = digitalRead(LINE_D1);
    int D2 = digitalRead(LINE_D2);
    int D3 = digitalRead(LINE_D3);
    int D4 = digitalRead(LINE_D4);
    int D5 = digitalRead(LINE_D5);

    if (D1==0 && D2==0 && D3==1 && D4==0 && D5==0) {
      //robot move forward
      std_fwd(HIGH_SPEED);
    } else if (D1==0 && D2==1 && D3==0 && D4==0 && D5==0) {
      //move to left
      std_left_fwd(HIGH_SPEED);
    } else if (D1==1 && D2==0 && D3==0 && D4==0 && D5==0) {
      //robot slowing down, move more to left
      std_left_fwd(MID_SPEED);
    } else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==0) {
      //move to right
      std_right_fwd(HIGH_SPEED);
    } else if (D1==0 && D2==0 && D3==0 && D4==0 && D5==1) {
      //robot slowing down, move more to right
      std_right_fwd(MID_SPEED);
    } else {
      // stop robot
      std_stp();
    }
    vTaskDelay(10 / portTICK_PERIOD_MS); // Small delay to allow RTOS to manage tasks efficiently
  }
}

void line_following_mecanum(void *pvParameters)
{
  for(;;){
    // Read line sensor values 
    int D1 = digitalRead(LINE_D1);
    int D2 = digitalRead(LINE_D2);
    int D3 = digitalRead(LINE_D3);
    int D4 = digitalRead(LINE_D4);
    int D5 = digitalRead(LINE_D5);

    if ((D1==0 && D2==1 && D3==1 && D4==1 && D5==0) || (D1==0 && D2==1 && D3==1 && D4==0 && D5==0) || (D1==0 && D2==0 && D3==1 && D4==1 && D5==0))
    {
      //robot move forward
      mecanum_move_fwd(MID_SPEED);
    } 

    //move to left
    else if ( (D1==1 && D2==1 && D3==1 && D4==0 && D5==0) || (D1==1 && D2==1 && D3==0 && D4==0 && D5==0)||(D1==0 && D2==1 && D3==0 && D4==0 && D5==0))
    {
      mecanum_turn_left(MID_SPEED, OFFSET_1);
    } 

    //robot slowing down, move more to left
    else if ((D1==1 && D2==0 && D3==0 && D4==0 && D5==0)) 
    {
      mecanum_turn_left(LOW_SPEED, OFFSET_2);
    } 
    
  //move to right
    else if ( (D1==0 && D2==0 && D3==1 && D4==1 && D5==1) || (D1==0 && D2==0 && D3==0 && D4==1 && D5==1)||(D1==0 && D2==0 && D3==0 && D4==1 && D5==0)) 
    {
      mecanum_turn_right(MID_SPEED, OFFSET_1);
    } 

  //robot slowing down, move more to right
    else if ((D1==0 && D2==0 && D3==0 && D4==0 && D5==1)) 
    {
      mecanum_turn_right(LOW_SPEED, OFFSET_2);
    } 

  // else if ((D1==1 && D2==1 && D3==1 && D4==1 && D5==1)  || (D1==0 && D2==0 && D3==0 && D4==0 && D5==0))
  // {
  //  mecanum_stp();
  // } 

    // else 
    // {
    //   // stop robot
    //   mecanum_move_rev(LOW_SPEED);
    //   vTaskDelay(1000 / portTICK_PERIOD_MS);  // Reverse for 1 second
    //   //mecanum_stp();  // Stop after reversing
    // }
    vTaskDelay(10 / portTICK_PERIOD_MS); // Small delay to allow RTOS to manage tasks efficiently
  }
}