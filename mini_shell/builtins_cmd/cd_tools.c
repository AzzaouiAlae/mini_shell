/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:36:00 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/08 05:18:41 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	count_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

int	get_stell_home(t_home_status set)
{
	static int	home;

	if (set == e_exist_home)
		home = 1;
	else if (set == e_missing_home)
		home = 0;
	return (home);
}

int	print_cd_error(char *arg)
{
	if (get_stell_home(0) == 1)
	{
		g_all.cmd_error_status = 1;
		if (arg[0] == '~' && (arg[1] && arg[1] != '~'))
		{
			perror(my_ft_strjoin("Minishell cd: ", get_from_env("HOME",
						arg)->content));
			return (1);
		}
		perror(my_ft_strjoin("Minishell cd: ", arg));
	}
	else
		write(2, "Minishell: cd: HOME not set\n", 28);
	return (1);
}

void	print_dash_error(void)
{
	char	*old_path;

	old_path = get_from_env("OLDPWD", NULL)->content;
	write(2, "Minishell: cd:", 14);
	write(2, old_path, ft_strlen(old_path));
	write(2, ": No such file or directory\n", 28);
}

int	check_dash(char *str)
{
	if (!ft_strncmp("--", str, 3))
		return (1);
	else if (!ft_strncmp("-", str, 2))
		return (1);
	return (0);
}
