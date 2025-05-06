/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:56 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:21:57 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_shell.h"
#include "split_by_token.h"

int	is_valid_var_char(t_split_data *data)
{
	if (!data->s[data->i])
		return (0);
	if (data->ch)
		return (1);
	if (!ft_strchr(" |<>\t", data->s[data->i]))
		return (1);
	return (0);
}

int	is_expand_variable(t_split_data *data)
{
	char	*s;

	if (data->s[data->i] != '$')
		return (0);
	data->type = e_args | is_cmd_type() | is_file_name() | e_var_to_get;
	g_all.token_str = cpp_str_new();
	while (is_valid_var_char(data))
		add_arg_type(data);
	if (data->type & e_file_name)
		data->type = e_file_name | e_var_to_get;
	s = str_find_char(&(data->s[data->i]), " |<>\t\"'=*/-+");
	if (s && (s[0] == '=' || (s[0] == '+' && s[1] == '=')))
		g_all.token->type = e_var_to_set | e_var_to_get;
	add_token(data);
	return (1);
}
