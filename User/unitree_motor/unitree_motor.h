//
// Created by w on 2025/6/7.
//

#ifndef CTRBOARD_H7_UART_UNITREE_MOTOR_H
#define CTRBOARD_H7_UART_UNITREE_MOTOR_H
#include "motor_control.h"
#include "motor_def.h"
typedef struct
{
    UART_HandleTypeDef channel;               // 电机CAN实例
    MOTOR_recv measure;            // 电机测量值
    MOTOR_send cmd;



//    motor_type_e motor_type;                // 电机类型
//    motor_working_type_e stop_flag;         // 启停标志
    motor_type_e motor_type;                // 电机类型
    motor_working_type_e stop_flag;         // 启停标志
    /* 监控线程相关 */
                    // 电机监控定时器

    /* 电机控制相关 */

    void *controller;            // 电机控+制器
    int16_t (*control)(MOTOR_recv measure);   // 控制电机的接口 用户可以自定义,返回值为16位的电压或电流值
} unitree_motor_object_t;
unitree_motor_object_t *unitree_motor_register(motor_config_t *config, void *control);
void unitree_motor_control();
#endif //CTRBOARD_H7_UART_UNITREE_MOTOR_H
