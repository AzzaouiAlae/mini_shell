/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_checkes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:03 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 10:56:44 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_env_vars.h"

int	valid_var_name(char *str)
{
	int		i;

	i = 1;
	if (!is_alpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i] && !ft_strchr(" |<>\t\"'=+", str[i]))
	{
		if (!is_valid_var_name_char(str[i]) && str[i] != '?')
			return (0);
		i++;
	}
	if (str[i] == '=' || (str[i] == '+' && str[i + 1] == '=') || !str[i])
		return (1);
	return (0);
}

int	is_env_var(t_set_env_vars *data)
{
	t_token	*tkn;

	tkn = data->tokens[data->i];
	if (!valid_var_name(tkn->s))
		return (0);
	if ((tkn->type & (e_var_to_set | e_set_var)))
	{
		if (tkn->type & e_set_var)
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

int	is_path(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
