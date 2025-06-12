//
// Created by w on 2025/6/7.
//

#include <malloc.h>
#include "unitree_motor.h"
#include "motor_def.h"
#include "motor_control.h"
static uint8_t idx = 0; // register idx,是该文件的全局电机索引,在注册时使用
/* DJI电机的实例,此处仅保存指针,内存的分配将通过电机实例初始化时通过malloc()进行 */
static unitree_motor_object_t *unitree_motor_obj[MOTOR_CNT] = {NULL};
void unitree_motor_enable(unitree_motor_object_t *motor_obj)
{
    motor_obj->stop_flag = MOTOR_ENALBED;
}
unitree_motor_object_t *unitree_motor_register(motor_config_t *config, void *control)
{


    unitree_motor_object_t *object = malloc(sizeof(unitree_motor_object_t));
    object->motor_type = config->motor_type;
    object->cmd.channel=config->channel;
    object->cmd=config->cmd;
    object->measure=config->measure;
    object->control = control;

    unitree_motor_enable(object); // 默认使能电机
    unitree_motor_obj[idx++] = object;

    return object;
}
void unitree_motor_relax(unitree_motor_object_t *motor_obj)
{
    motor_obj->stop_flag = MOTOR_STOP;
}
void unitree_motor_control()
{

    for (int i = 0; i < idx; i++)
    {
        if (unitree_motor_obj[i]->stop_flag == MOTOR_ENALBED)
        {
            SERVO_Send_recv(&unitree_motor_obj[i]->cmd, &unitree_motor_obj[i]->measure);
        }


    }

}