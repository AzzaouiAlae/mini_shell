/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 05:20:47 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/13 20:59:20 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_cpp_str	*get_from_env(char *var, char *arg)
{
	t_cpp_str	*str;
	t_cs_list	*value;

	str = cpp_str_new();
	value = cpp_map_get(g_all.custom_env, var);
	if (!value)
	{
		if (!ft_strncmp("HOME", var, 5))
			get_stell_home(e_missing_home);
		if (!ft_strncmp("OLDPWD", var, 7))
			write(2, "Minishell: cd: OLDPWD not set\n", 30);
		return (str);
	}
	if (arg)
		return (get_path(value->content, arg));
	cpp_str_add(str, value->content);
	return (str);
}

void	add_to_env(t_cpp_str *s, char *str_to_change, char *var)
{
	t_cs_list	*str;

	str = cs_list_new(1);
	if (s)
	{
		cs_list_add_range(str, s->count, s->content);
		str->type = e_global_var;
		cpp_map_add(g_all.custom_env, var, (void *)str);
	}
	else if (str_to_change)
	{
		cs_list_add_range(str, ft_strlen(str_to_change), str_to_change);
		str->type = e_global_var;
		cpp_map_add(g_all.custom_env, var, (void *)str);
	}
}
