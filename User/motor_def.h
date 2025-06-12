//
// Created by w on 2025/6/12.
//

#ifndef CTRBOARD_H7_UART_MOTOR_DEF_H
#define CTRBOARD_H7_UART_MOTOR_DEF_H
#include "usart.h"
#include "motor_control.h"
#define MOTOR_CNT 8

typedef enum
{
    MOTOR_TYPE_NONE = 0,
    GM6020,
    M3508,
    M2006,
    HT04,
    MF9025,
    GM6623,
    GO_M8010,
} motor_type_e;
typedef enum
{
    huart1_channel = 0,
    huart2_channel = 1,
}HUART_channel_e;
typedef enum
{
    MOTOR_STOP = 0,
    MOTOR_ENALBED = 1,
} motor_working_type_e;
typedef struct
{
    motor_type_e motor_type;
    UART_HandleTypeDef channel; // UART通道

    MOTOR_recv measure;            // 电机测量值
    MOTOR_send cmd;

    void *controller;              // 电机控制器
} motor_config_t;
#endif //CTRBOARD_H7_UART_MOTOR_DEF_H
