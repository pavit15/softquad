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

#define MOTOR_FORWARD 0
#define MOTOR_BACKWARD 1
#define MOTOR_STOP 2

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

void set_motor_speed(int direction, int duty_cycle) {
    int pwm_value = (duty_cycle * 255) / 100;

    gpio_set_level(PWM_PIN, pwm_value > 0 ? 1 : 0);

    if (direction == MOTOR_FORWARD) {
        gpio_set_level(MOTOR1_INPUT_1, 1);
        gpio_set_level(MOTOR1_INPUT_2, 0);
    } else if (direction == MOTOR_BACKWARD) {
        gpio_set_level(MOTOR1_INPUT_1, 0);
        gpio_set_level(MOTOR1_INPUT_2, 1);
    } else if (direction == MOTOR_STOP) {
        gpio_set_level(MOTOR1_INPUT_1, 0);
        gpio_set_level(MOTOR1_INPUT_2, 0);
    }

    if (direction == MOTOR_FORWARD) {
        gpio_set_level(MOTOR1_INPUT_3, 1);
        gpio_set_level(MOTOR1_INPUT_4, 0);
    } else if (direction == MOTOR_BACKWARD) {
        gpio_set_level(MOTOR1_INPUT_3, 0);
        gpio_set_level(MOTOR1_INPUT_4, 1);
    } else if (direction == MOTOR_STOP) {
        gpio_set_level(MOTOR1_INPUT_3, 0);
        gpio_set_level(MOTOR1_INPUT_4, 0);
    }
    
    if (direction == MOTOR_FORWARD) {
        gpio_set_level(MOTOR2_INPUT_1, 1);
        gpio_set_level(MOTOR2_INPUT_2, 0);
    } else if (direction == MOTOR_BACKWARD) {
        gpio_set_level(MOTOR2_INPUT_1, 0);
        gpio_set_level(MOTOR2_INPUT_2, 1);
    } else if (direction == MOTOR_STOP) {
        gpio_set_level(MOTOR2_INPUT_1, 0);
        gpio_set_level(MOTOR2_INPUT_2, 0);
    }

    if (direction == MOTOR_FORWARD) {
        gpio_set_level(MOTOR2_INPUT_3, 1);
        gpio_set_level(MOTOR2_INPUT_4, 0);
    } else if (direction == MOTOR_BACKWARD) {
        gpio_set_level(MOTOR2_INPUT_3, 0);
        gpio_set_level(MOTOR2_INPUT_4, 1);
    } else if (direction == MOTOR_STOP) {
        gpio_set_level(MOTOR2_INPUT_3, 0);
        gpio_set_level(MOTOR2_INPUT_4, 0);
    }

    gpio_set_level(MOTOR1_ENABLE_1, 1);
    gpio_set_level(MOTOR1_ENABLE_2, 1);
    gpio_set_level(MOTOR2_ENABLE_1, 1);
    gpio_set_level(MOTOR2_ENABLE_2, 1);
}

void pwm_task(void *arg) {
    motor_setup();

    while (1) {
        for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++) {
            set_motor_speed(MOTOR_FORWARD, duty_cycle);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }

        set_motor_speed(MOTOR_STOP, 0);
        vTaskDelay(100 / portTICK_PERIOD_MS);

        for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++) {
            set_motor_speed(MOTOR_BACKWARD, duty_cycle);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }

        set_motor_speed(MOTOR_STOP, 0);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void app_main() {
    xTaskCreate(&pwm_task, "pwm_task", 4096, NULL, 1, NULL);
}
