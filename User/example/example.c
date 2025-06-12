//
// Created by w on 2025/6/12.
//

#include <malloc.h>
#include "example.h"
#include"motor_def.h"
#include "motor_control.h"
#include "usart.h"
#include "unitree_motor.h"
#include "string.h"
static motor_config_t *example_motor_config;
unitree_motor_object_t *example_motor_object;
void init_example_motor()
{
    //memset(example_motor_config,0,sizeof(motor_config_t));
    // 为配置结构体分配内存
    example_motor_config = (motor_config_t *)malloc(sizeof(motor_config_t));
    if (example_motor_config == NULL) {
        // 内存分配失败处理
        return;
    }
    memset(example_motor_config, 0, sizeof(motor_config_t));
    example_motor_config->motor_type = GO_M8010;
    example_motor_config->cmd.channel = huart2;
    MOTOR_send *cmds=&example_motor_config->cmd;
    cmds->id=0;
    cmds->mode=1;
    cmds->T=0;
    cmds->W=70;
    cmds->Pos=0;
    cmds->K_P=0;
    cmds->K_W=0.05;

    example_motor_object=unitree_motor_register(example_motor_config,NULL);
    free(example_motor_config);
    example_motor_config = NULL;
}