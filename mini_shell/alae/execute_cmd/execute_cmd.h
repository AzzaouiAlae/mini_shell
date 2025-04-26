#ifndef EXECUTE_CMD_H
#define EXECUTE_CMD_H

#include "../../global.h"

typedef struct s_exe_cmd_data
{
    int i;
    int c;
    t_cmd **cmds;
    t_cmd *cmd;
    void (*builtin)(t_cmd *c);
} t_exe_cmd_data;

t_pipe *create_pipe();

#endif