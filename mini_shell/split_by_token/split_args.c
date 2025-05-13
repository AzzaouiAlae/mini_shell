/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:41 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/13 18:52:18 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_by_token.h"

int	check_double_dollar(t_split_data *data)
{
	if (data->type & e_var_to_get)
		return (0);
	if (data->s[data->i] == '$' && data->s[data->i + 1] == '$')
	{
		cpp_str_add_char(g_all.token_str, data->s[data->i]);
		data->i++;
		cpp_str_add_char(g_all.token_str, data->s[data->i]);
		return (1);
	}
	return (0);
}

void	add_arg_type(t_split_data *data)
{
	if (check_double_dollar(data))
		;
	else if (!is_dollar_to_skip(data))
		cpp_str_add_char(g_all.token_str, data->s[data->i]);
	if (is_var_to_get(data) && is_valid_var_name_char(data->s[data->i + 1]))
		data->type = data->type | e_var_to_get;
	else if (check_quote_in_arg(data))
		;
	else if (data->ch == data->s[data->i])
		data->ch = '\0';
	else if (!(data->type & e_path) && data->s[data->i] == '/')
		data->type = data->type | e_path;
	data->i++;
}

int	is_not_arg_type(t_split_data *data)
{
	char	*s;

	s = &(data->s[data->i]);
	if (ft_strchr("|<>\"'", *s))
		return (1);
	if (*s == '$' && *(s + 1) != '$')
	{
		if (*(s + 1) == '?')
			return (1);
		if (is_valid_var_name(s + 1))
			return (1);
	}
	return (0);
}

int	is_arg_char(t_split_data *data)
{
	if (!data->s[data->i])
		return (0);
	if (data->ch)
		return (1);
	if (!ft_strchr(" |<>\t", data->s[data->i]))
		return (1);
	return (0);
}

int	is_arg(t_split_data *data)
{
	data->type = e_args | is_cmd_type() | is_file_name();
	if (check_dollar_ch_arg(data))
		return (1);
	if (is_not_arg_type(data))
		return (0);
	g_all.token_str = cpp_str_new();
	if (check_export_cmd(data, "export"))
		return (1);
	if (is_var_to_set(data))
		data->type = e_var_to_set;
	while (is_arg_char(data))
		add_arg_type(data);
	if ((data->type & e_file_name) && (data->type & e_cmd))
		data->type -= e_cmd;
	add_token(data);
	return (1);
}
