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

void thread_indicator(void *pvParameters);

void setup() 
{
  Serial.begin(115200);

  init_input_instances();
  init_output_instances();

  thread_manager();
}

void loop() {}
