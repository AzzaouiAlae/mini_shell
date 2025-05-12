/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:52:36 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 04:18:15 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	invalid_cwd(char **cwd, char *arg, char *buf)
{
	*cwd = getcwd(buf, 4097);
	if (!(*cwd))
	{
		*cwd = my_ft_strjoin(get_from_env("PWD", NULL)->content, "/");
		*cwd = my_ft_strjoin(*cwd, arg);
		write(2, "error retrieving current directory: ", 36);
		write(2, "getcwd: cannot access parent directories: ", 42);
		write(2, "No such file or directory\n", 26);
	}
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

void	change_pwd_oldpwd(char *cmd, char *cwd)
{
	char	*pwd;

	add_to_env(get_from_env("PWD", NULL), NULL, "OLDPWD");
	if (cwd)
	{
		if (!ft_strncmp(cmd, cwd, ft_strlen(cmd)))
			cwd = getcwd(cwd, 4097);
		add_to_env(NULL, cwd, "PWD");
	}
	else
	{
		pwd = get_from_env("PWD", cmd)->content;
		if (!pwd || !pwd[0])
			pwd = getcwd(cwd, 4097);
		add_to_env(NULL, pwd, "PWD");
	}
}

int	check_other_path(char *buf, char *cwd, t_cmd *cmd)
{
	int	flag;

	flag = 0;
	if (cwd != NULL)
	{
		if (ft_strlen(cmd->args[1]) > 1 && cmd->args[1][ft_strlen(cmd->args[1])
			- 1] == '/')
			cmd->args[1][ft_strlen(cmd->args[1]) - 1] = '\0';
		cwd = get_from_env("PWD", cmd->args[1])->content;
		if (!cwd || cwd[0] == '\0')
			cwd = cmd->args[1];
		flag = 1;
	}
	else
		cwd = cmd->args[1];
	if (chdir(cwd) == -1 && print_cd_error(cmd->args[1]))
		return (0);
	if (!flag)
		invalid_cwd(&cwd, cmd->args[1], buf);
	change_pwd_oldpwd(cmd->args[1], cwd);
	return (1);
}

void	cd(t_cmd *cmd)
{
	char *cwd, *(buf);
	buf = ft_calloc(1, 4097);
	cwd = getcwd(buf, 4097);
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
		check_other_path(buf, cwd, cmd);
}
