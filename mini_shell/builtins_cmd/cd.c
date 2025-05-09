/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:52:36 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/08 20:51:15 by oel-bann         ###   ########.fr       */
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

void delete_path(t_cpp_str *str)
{
	if (str->content[str->count - 1] == '/')
		cpp_str_delete_char(str, str->count - 1);
	while (str->content[str->count - 1] != '/')
		cpp_str_delete_char(str, str->count - 1);
	cpp_str_delete_char(str, str->count - 1);
}
/*
cd 
/home/oel-bann/Desktop/sss/mini_shell/42_minishell_tester
*/

void add_kvp_env(t_cpp_str *str, char *key)
{
	t_cs_list *value;

	value = cs_list_new(sizeof(int));
	cs_list_add_range(value, str->count, str->content);
	cpp_map_add(g_all.custom_env, key, value);
}

int delete_dots(t_cpp_str *str, char *arg, int *i)
{
	if (!ft_strncmp(&(arg[*i]), "../", 3))
	{
		*i += 3;
		delete_path(str);
		return 1;
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
	return 0;
}

t_cpp_str	*get_path(char *pwd, char *arg)
{
	int i;
	t_cpp_str *str;

	str = cpp_str_new();
	cpp_str_add(str, pwd);
	i = 0;
	while (arg && arg[i])
	{
		if (!i && arg[i] == '~')
			i+=2;
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
	return str;
}

t_cpp_str	*get_from_env(char *var, char *arg)
{
	t_cpp_str	*str;
	t_cs_list	*value;
	char *pwd, *(cwd);

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
	if (!getcwd(cwd, 4097))
		return(cpp_str_add (str, getcwd(cwd, 4097)));
	if(arg)
		return (get_path(value->content, arg));
	cpp_str_add(str, value->content);
	return(str);
}

int	invalid_cwd(char **cwd, char *arg, char *buf)
{
	*cwd = getcwd(buf, 4097);
	if (!(*cwd))
	{
		*cwd = my_ft_strjoin(get_from_env("PWD", NULL)->content, "/");
		*cwd = my_ft_strjoin(*cwd, arg);
		write(2, "error retrieving current directory: ", 36);
		write(2, "getcwd: cannot access parent directories: ", 42);
		write(2, "No such file or directory\n", 26);
		return 1;
	}
	return 0;
}

void	cd_dash(t_cmd *cmd, char *buf)
{
	char *cwd, *(path);
	int (res) = 0;
	if (cmd->args[1][0] == '-' && cmd->args[1][1] == '\0')
	{
		path = get_from_env("OLDPWD", NULL)->content;
		res = chdir(get_from_env("OLDPWD", NULL)->content);
		if (res != -1)
		{
			write(1, path, ft_strlen(path));
			write(1, "\n", 1);
		}
		if (res == -1)
		{
			print_dash_error();
			return ;
		}
		cwd = getcwd(buf, 4097);
		add_to_env(get_from_env("PWD", NULL), NULL, "OLDPWD");
		add_to_env(NULL, cwd, "PWD");
	}
	else if (!ft_strncmp("--", cmd->args[1], 3))
	{
		cmd->args[1] = NULL;
		cd(cmd);
	}
}

char *change_pwd_oldpwd(char *cmd)
{
	char *pwd;

	add_to_env(get_from_env("PWD", NULL), NULL, "OLDPWD");
	pwd = get_from_env("PWD", cmd)->content;
	add_to_env(NULL, pwd, "PWD");
}

void	cd(t_cmd *cmd)
{
	char *cwd, *(buf);
	buf = ft_calloc(1, 4097);
	get_stell_home(e_exist_home);
	if (count_args(cmd->args) > 2)
	{
		g_all.cmd_error_status = 1;
		write(2, "Minishell : cd: too many arguments\n", 35);
	}
	else if (count_args(cmd->args) == 1 || (cmd->args[1]
			&& cmd->args[1][0] == '~'))
	{
		if (chdir(get_from_env("HOME", cmd->args[1])->content) == -1
			&& print_cd_error(cmd->args[1]))
			return ;
		add_to_env(get_from_env("PWD", NULL), NULL, "OLDPWD");
		add_to_env(NULL, get_from_env("HOME", cmd->args[1])->content, "PWD");
	}
	else if (cmd->args[1] && check_dash(cmd->args[1]))
		cd_dash(cmd, buf);
	else
	{
		cwd = get_from_env("PWD", cmd->args[1])->content;
		if (!cwd || cwd[0] == '\0')
			cwd = cmd->args[1];
		if (chdir(cwd) == -1 && print_cd_error(cmd->args[1]))
			return ;
		change_pwd_oldpwd(cmd->args[1]);
	}
}
