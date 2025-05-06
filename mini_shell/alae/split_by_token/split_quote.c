/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:59 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:22:00 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_shell.h"
#include "split_by_token.h"

int	is_char_in_db_quote(t_split_data *data)
{
	if (!data->s[data->i])
		return (0);
	if (data->ch)
		return (1);
	if (!ft_strchr(" |<>\t", data->s[data->i]))
		return (1);
	return (0);
}

int	is_double_quote(t_split_data *data)
{
	if ('"' != data->s[data->i])
		return (0);
	data->type = e_args | is_cmd_type() | is_file_name() | e_double_quote;
	g_all.token_str = cpp_str_new();
	if (check_export_cmd(data, "\"export\""))
		return (1);
	if (is_var_to_set(data))
		data->type = e_var_to_set;
	while (is_char_in_db_quote(data))
		add_arg_type(data);
	if ((data->type & e_file_name) && (data->type & e_cmd))
		data->type -= e_cmd;
	add_token(data);
	return (1);
}

int	is_single_quote(t_split_data *data)
{
	if ('\'' != data->s[data->i])
		return (0);
	data->type = e_args | is_cmd_type() | is_file_name() | e_quote;
	g_all.token_str = cpp_str_new();
	if (check_export_cmd(data, "'export'"))
		return (1);
	if (is_var_to_set(data))
		data->type = e_var_to_set;
	while (data->s[data->i] && (data->ch || !ft_strchr(" |<>\t",
				data->s[data->i])))
		add_arg_type(data);
	if ((data->type & e_file_name))
		data->type = e_file_name | e_quote;
	add_token(data);
	return (1);
}
