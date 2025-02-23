/**
 * @file input_config.cpp
 * @brief Input pins instances configuration
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

 #include <Arduino.h>
 #include "driver/gpio.h"
 #include "sdkconfig.h"
 #include "input_config.h"
 #include "Wire.h"
 #include "PS4Controller.h"
 
 /**
  * @brief Initialising output instances
  */
 void init_input_instances()
 {
   /** PS4 CONTROLLER **/
   PS4.begin(PS4_MAC_ADDRESS);
   
   /** LINE SENSOR **/
   pinMode(LINE_D1, INPUT);
   pinMode(LINE_D2, INPUT);
   pinMode(LINE_D3, INPUT);
   pinMode(LINE_D4, INPUT);
   pinMode(LINE_D5, INPUT);

 }