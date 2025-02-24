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
#include "tb6612.h"

/**
 * @brief Initialising output instances
 */
void init_output_instances(){
  /** THREAD INDICATOR **/
  gpio_pad_select_gpio(BLINK_GPIO1);
  gpio_set_direction(BLINK_GPIO1, GPIO_MODE_OUTPUT);
}

