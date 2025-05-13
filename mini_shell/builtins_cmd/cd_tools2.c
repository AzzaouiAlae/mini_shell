/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:17:18 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/13 20:44:46 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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

char	*clean_slash(char *arg)
{
	int			i;
	t_cpp_str	*str;

	str = cpp_str_new();
	cpp_str_add(str, arg);
	i = 0;
	while (i < str->count)
	{
		if (i && str->content[i - 1] == '/' && str->content[i] == '/')
			cpp_str_delete_char(str, i);
		else
			i++;
	}
	return (str->content);
}

int	is_absolute_path(t_cpp_str	*str, char *arg)
{
	if (arg && arg[0] == '/')
		cpp_str_add(str, arg);
	if (str->count)
		return (1);
	return (0);
}

t_cpp_str	*get_path(char *pwd, char *arg)
{
	int			i;
	t_cpp_str	*str;

	i = 0;
	arg = clean_slash(arg);
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
