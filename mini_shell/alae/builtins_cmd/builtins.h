#ifndef BUILTINS_H
#define BUILTINS_H

#include "../../global.h"
#include "../../ft_func/ft_func.h"

void print_export_vars_cmd(t_cmd *cmd);
void cd(t_cmd);
void echo(t_cmd);
void env(t_cmd);
void exit_cmd(t_cmd);
void pwd(t_cmd);
void unset(t_cmd);

#endif