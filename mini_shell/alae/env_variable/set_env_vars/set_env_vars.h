#ifndef SET_ENV_VARS_H
# define SET_ENV_VARS_H
# include "../../split_by_token/split_by_token.h"
# include "../env_var.h"

typedef struct s_set_env_vars
{
	int		i;
	int		j;
	int		type;
	int		count;
	int		has_cmd;
	int		is_export_args;
	char	**args;
	t_token	**tokens;
}			t_set_env_vars;

int delete_export_token(t_set_env_vars *data);
int	is_env_var(t_set_env_vars *data);
int	is_tokens_has_cmd(void);
int is_path(char *s);

#endif