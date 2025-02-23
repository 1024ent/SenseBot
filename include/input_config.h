/**
 * @file input_config.h
 * @brief Input pins instances configuration
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */
#ifndef __INPUT_CONFIG_H__
#define __INPUT_CONFIG_H__

/** INPUT PINS DECLARATION */
/** Line Sensor **/ 
#define   LINE_D1     33
#define   LINE_D2     32
#define   LINE_D3     35
#define   LINE_D4     34
#define   LINE_D5     36

/** PS4 CONTROLLER **/
#if ROBOT_SYSTEM == ROBOT_1

    #define PS4_MAC_ADDRESS "aa:bb:cc:dd:ee:ff"

#elif ROBOT_SYSTEM == ROBOT_2

    #define PS4_MAC_ADDRESS "a8:42:e3:8f:fa:06"

#endif

void init_input_instances();

#endif