#ifndef BUILTINS_H
#define BUILTINS_H

#include "../../global.h"
#include "../../ft_func/ft_func.h"
#include "../../mini_shell.h"
void print_export_vars_cmd(t_cmd *cmd);
void cd(t_cmd *cmd);
void echo(t_cmd *cmd);
void env(t_cmd *cmd);
void exit_cmd(t_cmd *cmd);
void pwd(t_cmd *cmd);
void unset(t_cmd *cmd);
int count_args(char **args);
#endif