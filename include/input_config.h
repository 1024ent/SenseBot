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
#define PS4_MAC_ADDRESS "14:2b:2f:c0:28:fe"

/** Line Sensor **/ 
#define   LINE_D1     33
#define   LINE_D2     32
#define   LINE_D3     35
#define   LINE_D4     34
#define   LINE_D5     36

void init_input_instances();

#endif