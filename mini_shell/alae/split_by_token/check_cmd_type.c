/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:23 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:21:24 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_shell.h"
#include "split_by_token.h"

int	last_cmd_type(void)
{
	t_token	**token;

	if (!g_all.tokens->count)
		return (e_none);
	token = g_all.tokens->content;
	return (token[g_all.tokens->count - 1]->type);
}

int	is_cmd_type(void)
{
	int		i;
	int		j;
	t_token	**tokens;

	i = 0;
	tokens = g_all.tokens->content;
	if (!g_all.tokens->count)
		return (e_cmd);
	while (i < g_all.tokens->count)
	{
		j = g_all.tokens->count - 1 - i;
		if (tokens[j]->type & e_cmd)
			return (0);
		if (!j || (tokens[j]->type & (e_pipe)))
			return (e_cmd);
		i++;
	}
	return (e_none);
}

int	is_file_name(void)
{
	int	type;

	type = last_cmd_type();
	if (type & (e_redir_in | e_redir_out_app | e_redir_out_trun))
		return (e_file_name);
	return (e_none);
}
