#ifndef DEBUG_H
#define DEBUG_H
#include "mini_shell.h"

void print_cmds();
void print_func_data(char *str, void (*func)(void));
void print_cmd(t_cmd *cmd);
void process_cmd(char *s);
char *get_enum_str(int type);
void print_tokens();

#endif