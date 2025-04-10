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
#define     STBY        GPIO_NUM_23

// TB6612FNG PWM PIN LEFT MOTOR
#define     LEFT_PWM    GPIO_NUM_13
const int pwmChannel_left = 0;       // PWM channel (0-15)
const int FL_offset = 1;
const int RL_offset = 1;

// TB6612FNG PWM PIN RIGHT MOTOR
#define     RIGHT_PWM   GPIO_NUM_4
const int pwmChannel_right = 1;       // PWM channel (0-15)
const int FR_offset = 1;
const int RR_offset = 1;

// LEFT FRONT MOTOR
#define     LEFT_AIN1  GPIO_NUM_27
#define     LEFT_AIN2  GPIO_NUM_14

// LEFT REAR MOTOR
#define     LEFT_BIN1   GPIO_NUM_26
#define     LEFT_BIN2   GPIO_NUM_25

// RIGHT FRONT MOTOR
#define     RIGHT_AIN1  GPIO_NUM_21
#define     RIGHT_AIN2  GPIO_NUM_22

// RIGHT REAR MOTOR
#define     RIGHT_BIN1  GPIO_NUM_19
#define     RIGHT_BIN2  GPIO_NUM_18

/** THREAD INDICATOR **/
#define     BLINK_GPIO1 GPIO_NUM_2

void init_output_instances();

#endif