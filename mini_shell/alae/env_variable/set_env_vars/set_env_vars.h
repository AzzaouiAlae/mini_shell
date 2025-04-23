#ifndef SET_ENV_VARS_H
# define SET_ENV_VARS_H
# include "../../split_by_token/split_by_token.h"
# include "../env_var.h"

typedef struct s_set_env_vars
{
	int		has_cmd;
	int		count;
	int		i;
	int		j;
	int		is_export_args;
	int		type;
	t_token	**tokens;
	char	**args;
}			t_set_env_vars;

int	is_env_var(t_set_env_vars *data);
int	is_tokens_has_cmd(void);

#endif