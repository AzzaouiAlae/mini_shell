#ifndef ENV_VAR_H
# define ENV_VAR_H
# include "../../global.h"
# include "../../mini_shell.h"
# include "../../ft_func/ft_func.h"
# include "../split_by_token/split_by_token.h"

typedef enum e_var_type
{
	e_local_var,
	e_global_var
}		t_var_type;

char	**split_var_token(t_cpp_str *str_token);
int		is_var_start(t_cpp_str *str, char ch);
void	print_env_vars(void);

#endif