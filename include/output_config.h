/**
 * @file output_config.h
 * @brief Output pins instances configuration
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#ifndef __OUTPUT_CONFIG_H__
#define __OUTPUT_CONFIG_H__

/** OUTPUT PINS DECLARATION */
// TB6612FNG STBY PIN
#define   STBY        10

// TB6612FNG PWM PIN LEFT MOTOR
#define   LEFT_PWM    13
const int pwmChannel_left = 1;       // PWM channel (0-15)
const int pwmFrequency_left = 5000;  // Frequency in Hz
const int pwmResolution_left = 8;    // Resolution in bits (0-255)

// TB6612FNG PWM PIN RIGHT MOTOR
#define   RIGHT_PWM   4
const int pwmChannel_right = 0;       // PWM channel (0-15)
const int pwmFrequency_right = 5000;  // Frequency in Hz
const int pwmResolution_right = 8;    // Resolution in bits (0-255)

// LEFT FRONT MOTOR
#define   LEFT_AIN1  27
#define   LEFT_AIN2  14

// LEFT REAR MOTOR
#define   LEFT_BIN1  26
#define   LEFT_BIN2  25

// RIGHT FRONT MOTOR
#define   RIGHT_AIN1  19
#define   RIGHT_AIN2  18

// RIGHT REAR MOTOR
#define   RIGHT_BIN1  21
#define   RIGHT_BIN2  22

/** THREAD INDICATOR **/
#define BLINK_GPIO1 GPIO_NUM_2

/** MOTOR DRIVER **/

void init_output_instances();

#endif