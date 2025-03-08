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
#include "line_following.h"
#include "controller_manager.h"

/** 
 * @brief Task handles for managing different threads 
 */
TaskHandle_t myThreadIndicator = NULL;
TaskHandle_t stdLineFollowing = NULL;
TaskHandle_t mcnLineFollowing = NULL;

/**
 * @brief Initializes and creates tasks for concurrent execution.
 * 
 * This function sets up FreeRTOS tasks, assigning them to specific CPU cores 
 * for optimized performance. Tasks will execute according to their assigned priority.
 */
void thread_manager()
{
    /**
     * @brief Creating FreeRTOS tasks and assigning them to cores.
     * 
     * @details xTaskCreatePinnedToCore(
     *            TaskFunction_t pvTaskCode,   // Pointer to the function implementing the task
     *            const char *pcName,         // Name of the task (for debugging)
     *            uint32_t usStackDepth,      // Stack size allocated to the task (in words)
     *            void *pvParameters,         // Task parameters (set to NULL if unused)
     *            UBaseType_t uxPriority,     // Task priority (1 = lowest, 15 = highest)
     *            TaskHandle_t *pxCreatedTask,// Handle for the created task
     *            BaseType_t xCoreID          // Core to which the task is pinned (0 or 1)
     *          )
     */

    // Task for blinking an LED to indicate system status (Runs on Core 0 with low priority)
    xTaskCreatePinnedToCore(thread_indicator, 
                            "Blinking LED", 
                            2048, 
                            NULL, 
                            1, 
                            &myThreadIndicator, 
                            0);

    // Uncomment if using standard wheel line-following task
    // xTaskCreatePinnedToCore(line_following_std, 
    //                         "Standard Wheel Line Following", 
    //                         4096, 
    //                         NULL, 
    //                         1, 
    //                         &stdLineFollowing, 
    //                         1);

    // Task for line-following using a mecanum wheel system (Runs on Core 1)
    xTaskCreatePinnedToCore(line_following_mecanum, 
                            "Mecanum Wheel Line Following", 
                            4096, 
                            NULL, 
                            1, 
                            &mcnLineFollowing, 
                            1);
}
 
