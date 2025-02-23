/**
 * @file output_config.cpp
 * @brief Output pins instances configuration
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#include <Arduino.h>
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "output_config.h"
/**
 * @brief Initialising output instances
 */
void init_output_instances()
{
  /** THREAD INDICATOR **/
  gpio_pad_select_gpio(BLINK_GPIO1);
  gpio_set_direction(BLINK_GPIO1, GPIO_MODE_OUTPUT);
  
 
  // /** MOTOR DRIVER **/
  // // Left motor TB6612FNG pins
  // ledcSetup(pwmChannel_left, pwmFrequency_left, pwmResolution_left);
  // ledcAttachPin(LEFT_PWM, pwmChannel_left);
  // pinMode(LEFT_AIN1, OUTPUT);
  // pinMode(LEFT_AIN2, OUTPUT);
  // pinMode(LEFT_BIN1, OUTPUT);
  // pinMode(LEFT_BIN2, OUTPUT);

  // // Right motor TB6612FNG pins
  // ledcSetup(pwmChannel_right, pwmFrequency_right, pwmResolution_right);
  // ledcAttachPin(RIGHT_PWM, pwmChannel_right);
  // pinMode(RIGHT_AIN1, OUTPUT);
  // pinMode(RIGHT_AIN2, OUTPUT);
  // pinMode(RIGHT_BIN1, OUTPUT);
  // pinMode(RIGHT_BIN2, OUTPUT); 
}

