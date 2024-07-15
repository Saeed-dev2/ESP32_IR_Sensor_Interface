/**
 * @file main.c
 * @brief IR sensor example using ESP-IDF
 * 
 * This file contains an example of how to interface an Infrared (IR) sensor 
 * with an ESP32 using the ESP-IDF framework. The program reads the IR sensor's 
 * output and prints its state to the serial monitor.
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

/**
 * @brief GPIO pin number where the IR sensor is connected
 */
#define IR_SENSOR_PIN GPIO_NUM_4

/**
 * @brief Main application entry point
 * 
 * Configures the IR sensor pin as an input, reads its value in a loop, and
 * prints the state to the serial monitor.
 */

void app_main(void)
{
    // Configure the IR sensor pin as input
    gpio_config_t io_conf;
    // Disable interrupt for the pin
    io_conf.intr_type = GPIO_INTR_DISABLE; 
    // Set the pin as input mode 
    io_conf.mode = GPIO_MODE_INPUT;  
    // Bit mask for the pin       
    io_conf.pin_bit_mask = (1ULL << IR_SENSOR_PIN);  
    // Disable pull-down mode
    io_conf.pull_down_en = 0;  
    // Enable pull-up mode             
    io_conf.pull_up_en = 1;      
    // Apply the configuration          
    gpio_config(&io_conf);                

    while (1)
    {
        // Read the IR sensor value from the specified GPIO pin
        int ir_value = gpio_get_level(IR_SENSOR_PIN);

        // Print the sensor value to the serial monitor
        if (ir_value == 0)
        {
            // IR sensor detected an object
            printf("Object detected!\n");  
        }
        else
        {
            // No object detected by the IR sensor
            printf("No object detected.\n"); 
        }

        // Delay for 1000 milliseconds (1 second) before reading again
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
