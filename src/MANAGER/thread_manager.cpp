/**
 * @file thread_manager.cpp
 * @brief Spawning application threads
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#include <Arduino.h>
#include "driver/gpio.h"
#include "blink_manager.h"
#include "sdkconfig.h"
#include "std_movement.h"
#include "mecanum_movement.h"
#include "controller_manager.h"

/** Tasks Structs **/
TaskHandle_t myThreadIndicator = NULL;

/**
 * @brief Initialising threads and spawn them
 */
void thread_manager()
{
    /**
     * @brief Creating tasks to run simultaneously according to priority
     * @details xTaskCreate(
     *                           TaskFunction_t pvTaskCode, [name of task function]
     *                           const char * const pcName, [messages]
     *                           const uint32_t usStackDepth, [Words, not bytes!]
     *                          void * const pvParameters, [usually NULL]
     *                           UBaseType_t uxPriority, [priority level (1(LOWEST) to 15(HIGHEST))]
     *                          TaskHandle_t * const pxCreatedTask) PRIVILEGED_FUNCTION
     */
    //xTaskCreate(send_and_parse_value, "Connecting to UART ...", 10000, NULL, tskIDLE_PRIORITY, &myUART);
    xTaskCreate(thread_indicator, "Blinking LED", 4096, NULL, 1, &myThreadIndicator);
}