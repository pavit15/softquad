#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

//pin definitions
#define MOTOR1_INPUT_1 14
#define MOTOR1_ENABLE_1 27
#define MOTOR1_INPUT_2 33
#define MOTOR1_ENABLE_2 32
#define MOTOR1_INPUT_3 25
#define MOTOR1_INPUT_4 26
#define MOTOR2_INPUT_1 19
#define MOTOR2_ENABLE_1 18
#define MOTOR2_INPUT_2 16
#define MOTOR2_ENABLE_2 4
#define MOTOR2_INPUT_3 17
#define MOTOR2_INPUT_4 5
#define PWM_PIN 13

#define MOTOR_Set0 0
#define MOTOR_Set1 1

void motor_setup() {
    gpio_pad_select_gpio(MOTOR1_INPUT_1);
    gpio_set_direction(MOTOR1_INPUT_1, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR1_ENABLE_1);
    gpio_set_direction(MOTOR1_ENABLE_1, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR1_INPUT_2);
    gpio_set_direction(MOTOR1_INPUT_2, GPIO_MODE_OUTPUT);
    
    gpio_pad_select_gpio(MOTOR1_ENABLE_2);
    gpio_set_direction(MOTOR1_ENABLE_2, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR1_INPUT_3);
    gpio_set_direction(MOTOR1_INPUT_3, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR1_INPUT_4);
    gpio_set_direction(MOTOR1_INPUT_4, GPIO_MODE_OUTPUT);
    
    gpio_pad_select_gpio(MOTOR2_INPUT_1);
    gpio_set_direction(MOTOR2_INPUT_1, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR2_ENABLE_1);
    gpio_set_direction(MOTOR2_ENABLE_1, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR2_INPUT_2);
    gpio_set_direction(MOTOR2_INPUT_2, GPIO_MODE_OUTPUT);
    
    gpio_pad_select_gpio(MOTOR2_ENABLE_2);
    gpio_set_direction(MOTOR2_ENABLE_2, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR2_INPUT_3);
    gpio_set_direction(MOTOR2_INPUT_3, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(MOTOR2_INPUT_4);
    gpio_set_direction(MOTOR2_INPUT_4, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(PWM_PIN);
    gpio_set_direction(PWM_PIN, GPIO_MODE_OUTPUT);

    gpio_set_level(MOTOR1_INPUT_1, 0);
    gpio_set_level(MOTOR1_ENABLE_1, 0);
    gpio_set_level(MOTOR1_INPUT_2, 0);
    gpio_set_level(MOTOR1_ENABLE_2, 0);
    gpio_set_level(MOTOR1_INPUT_3, 0);
    gpio_set_level(MOTOR1_INPUT_4, 0);
    gpio_set_level(MOTOR2_INPUT_1, 0);
    gpio_set_level(MOTOR2_ENABLE_1, 0);
    gpio_set_level(MOTOR2_INPUT_2, 0);
    gpio_set_level(MOTOR2_ENABLE_2, 0);
    gpio_set_level(MOTOR2_INPUT_3, 0);
    gpio_set_level(MOTOR2_INPUT_4, 0);
    gpio_set_level(PWM_PIN, 0);
}

void set_motor_speed(int set, int duty_cycle) {
    int pwm_value = (duty_cycle * 255) / 100;
    gpio_set_level(PWM_PIN, pwm_value > 0 ? 1 : 0);

    if (set == MOTOR_Set0) {
        // Control SET1 motors
        // Forward motion
        gpio_set_level(MOTOR1_INPUT_1, 1);
        gpio_set_level(MOTOR1_INPUT_2, 0);
        gpio_set_level(MOTOR2_INPUT_1, 1);
        gpio_set_level(MOTOR2_INPUT_2, 0);
    } else if (set == MOTOR_Set1) {
        // Control SET2 motors
        // Forward motion
        gpio_set_level(MOTOR1_INPUT_3, 1);
        gpio_set_level(MOTOR1_INPUT_4, 0);
        gpio_set_level(MOTOR2_INPUT_3, 1);
        gpio_set_level(MOTOR2_INPUT_4, 0);
    }
}
void trot_gait() {
    motor_setup();

    int trot_speed = 50; // Adjust the speed as needed
    int firstStart = 1; // Flag to track the first start

    while (1) {
        if (firstStart) {
            // Trot SET1 forward (diagonal motors)
            set_motor_speed(MOTOR_Set0, trot_speed);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            // Trot SET2 forward (opposite diagonal motors)
            set_motor_speed(MOTOR_Set1, trot_speed);

            firstStart = 0; // Set the flag to 0 after the first start
        } else {
            // Trot SET1 forward without delay as it's leading
            set_motor_speed(MOTOR_Set0, trot_speed);
            // Trot SET2 forward (opposite diagonal motors)
            set_motor_speed(MOTOR_Set1, trot_speed);
        }
    }
}
void app_main() {
    xTaskCreate(&trot_gait, "trot_gait", 4096, NULL, 1, NULL);
}