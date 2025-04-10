/**
 * @file main.cpp
 * @brief main ESP32 Mainboard
 * @copyright UMPSA ROBOTICS
 * @license Loo Hui Kie [ELPROG]
 */
#include <Arduino.h>
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "PS4Controller.h"
#include "thread_manager.h"
#include "input_config.h"
#include "output_config.h"
#include "mecanum_movement.h"

#define     MID_SPEED           125    
#define     HIGH_SPEED          255    
#define     LOW_SPEED           90

void setup() 
{
  Serial.begin(115200);

  init_input_instances();
  init_output_instances();

  thread_manager();
}

void loop() {
      
}
