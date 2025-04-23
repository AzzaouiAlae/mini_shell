#include "set_env_vars.h"

int	is_env_var(t_set_env_vars *data)
{
    t_token *tkn;

    tkn = data->tokens[data->i];
	if ((tkn->type & (e_var_to_set | e_set_var)))
	{
		if(tkn->type & e_set_var)
			data->type = e_global_var;
		return (1);
	}
	if (((tkn->type & e_args) && data->is_export_args))
		return (1);
	return (0);
}

int	is_tokens_has_cmd(void)
{
	t_token	**tokens;
	int		i;

	i = 0;
	tokens = g_all.tokens->content;
	while (g_all.tokens->count > i)
	{
		if ((tokens[i]->type & e_cmd) && !(tokens[i]->type & e_set_var))
			return (1);
		i++;
	}
	return (0);
}
