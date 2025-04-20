#ifndef ENV_VAR_H
#define ENV_VAR_H
#include "../../mini_shell.h"
#include "../../ft_func/ft_func.h"
#include "../split_by_token/split_by_token.h"

void add_env_var(char *kvp);
char *get_key_in_token(t_cpp_str *str, t_cpp_str *new_str_token);
int get_type_without_set_var(int type);

#endif