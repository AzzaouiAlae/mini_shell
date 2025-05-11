/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:29 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 23:01:22 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"

void	create_kvp(char *key_value)
{
	t_cs_list	*value;
	t_cpp_str	*str;
	int			i;

	i = 0;
	str = cpp_str_new();
	while (key_value[i] && key_value[i] != '=')
		cpp_str_add_char(str, key_value[i++]);
	if (!key_value[i])
		return ;
	value = cs_list_new(sizeof(char));
	i++;
	while (key_value[i])
		cs_list_add(value, (long)(key_value[i++]));
	value->type = e_global_var;
	cpp_map_add(g_all.custom_env, str->content, value);
}

void	init_env_map(void)
{
	int			i;
	t_cpp_str	*str;

	i = 0;
	g_all.custom_env = cpp_map_new_capacity(150);
	while (g_all.env[i])
	{
		create_kvp(g_all.env[i]);
		i++;
	}
	i = 0;
	while (g_all.argv[i])
	{
		str = ft_itoa(i);
		cpp_str_add(str, "=");
		cpp_str_add(str, g_all.argv[i]);
		add_env_var(str->content, e_local_var);
		i++;
	}
	set_exit_status();
}

void	add_env(t_key_value *kvp)
{
	t_cs_list	*value;
	t_cpp_str	*str;

	value = kvp->value;
	if (!value->type)
		return ;
	str = cpp_str_new();
	cpp_str_add(str, kvp->key);
	cpp_str_add(str, "=");
	cpp_str_add(str, value->content);
	cs_list_add(g_all.new_env, (long)str->content);
}
