/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_var_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:37 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 10:57:56 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"

void	create_arg_token(t_cpp_str *arg, t_cpp_str *str_token, int *i)
{
	char	ch;

	ch = '\0';
	while (str_token->content[0])
	{
		if (!ch && ft_strchr("\"'", str_token->content[0])
			&& cs_list_contains(g_all.ch_i, *i))
			ch = str_token->content[0];
		else if (ch == str_token->content[0] && cs_list_contains(g_all.ch_i,
				*i))
			ch = '\0';
		else if (ch || !ft_strchr(" \t", str_token->content[0]))
			cpp_str_add_char(arg, str_token->content[0]);
		else
			return ;
		cpp_str_delete_char(str_token, 0);
		(*i)++;
	}
}

void	pass_space(t_cpp_str *str_token, int *i)
{
	while (ft_strchr(" \t", str_token->content[0]))
	{
		(*i)++;
		cpp_str_delete_char(str_token, 0);
	}
}

char	**split_var_token(t_cpp_str *str_token)
{
	int			i;
	t_cs_list	*args;
	t_cpp_str	*arg;

	args = cs_list_new(sizeof(char *));
	arg = cpp_str_new();
	i = 0;
	pass_space(str_token, &i);
	while (str_token->content[0])
	{
		create_arg_token(arg, str_token, &i);
		if (arg->count)
			cs_list_add(args, (long)arg->content);
		else
			return (args->content);
		arg = cpp_str_new();
		pass_space(str_token, &i);
	}
	return (args->content);
}
