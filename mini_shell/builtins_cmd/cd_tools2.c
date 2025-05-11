/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:17:18 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/11 20:34:38 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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

void	delete_path(t_cpp_str *str)
{
	if (str->content[str->count - 1] == '/')
		cpp_str_delete_char(str, str->count - 1);
	while (str->content[str->count - 1] != '/')
		cpp_str_delete_char(str, str->count - 1);
	cpp_str_delete_char(str, str->count - 1);
}

int	delete_dots(t_cpp_str *str, char *arg, int *i)
{
	if (!ft_strncmp(&(arg[*i]), "../", 3))
	{
		*i += 3;
		delete_path(str);
		return (1);
	}
	if (!ft_strncmp(&(arg[*i]), "..", 2))
	{
		*i += 2;
		delete_path(str);
		return (1);
	}
	else if (!ft_strncmp(&(arg[*i]), "./", 2))
	{
		*i += 2;
		return (1);
	}
	else if (!ft_strncmp(&(arg[*i]), ".", 1))
	{
		(*i)++;
		return (1);
	}
	return (0);
}

int is_absolute_path(t_cpp_str	*str, char *arg)
{
	int i;

	i = 0;
	if (arg && arg[0] == '/')
	{
		while (arg[i])
		{
			if (!i || !(arg[i - 1] == '/' && arg[i] == '/') )
				cpp_str_add_char(str, arg[i]);
			i++;
		}
		
	}
	if (str->count)
		return (1);
	return 0;
}

t_cpp_str	*get_path(char *pwd, char *arg)
{
	int			i;
	t_cpp_str	*str;

	i = 0;
	str = cpp_str_new();
	if (is_absolute_path(str, arg))
		return (str);
	cpp_str_add(str, pwd);
	while (arg && arg[i])
	{
		if (!i && arg[i] == '~')
			i += 2;
		if (i && arg[i] == '/')
			i++;
		if (arg[i] && !delete_dots(str, arg, &i))
		{
			if (arg[i] && str->content[str->count - (str->count > 0)] != '/')
				cpp_str_add_char(str, '/');
			while (arg[i] && arg[i] != '/')
				cpp_str_add_char(str, arg[i++]);
		}
	}
	return (str);
}

t_cpp_str	*get_from_env(char *var, char *arg)
{
	t_cpp_str	*str;
	t_cs_list	*value;

	char *(cwd);
	str = cpp_str_new();
	cwd = ft_calloc(1, 4097);
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
