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
 motor_config_t example_motor_config={
    .motor_type = GO_M8010,
    //.channel = usart2_485,
    .cmd = {
         .channel= usart2_485,
        .id = 0,
        .mode = 1,
        .T = 0,
        .W = 70,
        .Pos = 0,
        .K_P = 0,
        .K_W = 0.05
    }
};
unitree_motor_object_t *example_motor_object;

void init_example_motor()
{

    example_motor_object=unitree_motor_register(&example_motor_config,NULL);

}