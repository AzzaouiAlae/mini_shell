/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:11 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 05:38:49 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_env_vars.h"

t_cs_list	*create_value_list(char *s, int type)
{
	t_cs_list	*str;
	int			i;

	i = 1;
	str = cs_list_new_capacity(1, ft_strlen(s));
	while (s[i])
	{
		cs_list_add(str, s[i]);
		i++;
	}
	str->type = type;
	return (str);
}

void	add_env_var(char *kvp, int type)
{
	t_add_env_var	data;

	ft_bzero(&data, sizeof(t_add_env_var));
	data.s = str_find_char(kvp, "+=");
	if (!(data.s))
		return ;
	data.key_len = ft_strlen_delimiter(kvp, "+=");
	data.str_key = cpp_str_new();
	data.str_val = cpp_str_new();
	cpp_str_add_len(data.str_key, kvp, data.key_len);
	if (*(data.s) == '+')
	{
		data.val_list = cpp_map_get(g_all.custom_env, data.str_key->content);
		if (!(data.val_list))
			data.val_list = create_value_list(data.s, type);
		(data.s)++;
		data.val = create_value_list(data.s, type);
		cs_list_add_range(data.val_list, data.val->count, data.val->content);
	}
	else
		data.val_list = create_value_list(data.s, type);
	cpp_map_add(g_all.custom_env, data.str_key->content, data.val_list);
}

void	print_export_error(t_set_env_vars *data)
{
	t_token		*tkn;
	t_cpp_str	*str;

	str = cpp_str_new();
	tkn = data->tokens[data->i];
	cpp_str_add(str, "mini-shell: export: `");
	cpp_str_add(str, tkn->s);
	g_all.cmd_error_status = 1;
	if (tkn->s[0] == '-')
	{
		g_all.cmd_error_status = 2;
		cpp_str_add(str, "': invalid option\n");
	}
	else
		cpp_str_add(str, "': not a valid identifier\n");
	write(2, str->content, str->count);
	cs_list_delete(g_all.tokens, data->i);
	data->i--;
}

void	add_var_to_env(t_set_env_vars *data)
{
	t_token	*tkn;

	tkn = data->tokens[data->i];
	if (tkn->type & e_pipe)
		data->is_export_args = 0;
	if (is_env_var(data))
	{
		if ((tkn->type & e_set_var))
			data->is_export_args = 1;
		else if (!(data->has_cmd))
			add_env_var(data->tokens[data->i]->s, data->type);
	}
	else if (tkn->type & (e_var_to_set | e_args) && !(tkn->type & e_cmd))
	{
		if (data->is_export_args)
			print_export_error(data);
		else
			tkn->type = e_args | is_cmd_type() | is_file_name()
				| is_path(tkn->s);
	}
}

void	add_vars_to_env(void)
{
	t_set_env_vars	data;

	ft_bzero(&data, sizeof(t_set_env_vars));
	data.has_cmd = is_tokens_has_cmd();
	data.tokens = g_all.tokens->content;
	data.count = g_all.tokens->count;
	while (g_all.tokens->count > data.i)
	{
		add_var_to_env(&data);
		data.i++;
	}
}
