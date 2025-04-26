#ifndef GET_ENV_VARS_H
# define GET_ENV_VARS_H
#include "../env_var.h"
# include "../../split_by_token/split_by_token.h"

typedef struct s_get_env_data
{
	int			i;
	int			j;
	int type;
	char		**args;
	t_token		**tokens;
	t_cpp_str	*new_str_token;
	t_cpp_str	*str_token;
}				t_get_env_data;

int del_set_var(int type);
void add_var_args(t_get_env_data *data);
void add_var_to_tokens(t_get_env_data *data);
void create_value_token(t_get_env_data *data);
char *create_key_token(t_cpp_str *str, t_cpp_str *new_str_token);

#endif