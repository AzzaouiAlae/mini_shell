/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:23 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 11:29:00 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_too_many_arguments(t_cmd *cmd)
{
	int	len;

	len = ft_strslen(cmd->args);
	if (len > 2)
	{
		write(2, "Minishell: exit: too many arguments\n", 36);
		ft_exit(1);
	}
}

int	is_num(t_cmd *cmd, int i)
{
	if (i > 19)
		return (1);
	if ((!i && cmd->args[1][i] == '-'))
		return (0);
	if ((!i && cmd->args[1][i] == '+'))
		return (0);
	if (is_digit(cmd->args[1][i]))
		return (0);
	return (1);
}

void	print_num_error(char *arg)
{
	t_cpp_str	*str;

	str = cpp_str_new();
	cpp_str_add(str, "exit: ");
	cpp_str_add(str, arg);
	cpp_str_add(str, ": numeric argument required\n");
	write(2, str->content, str->count);
	ft_exit(2);
}

void	check_is_num(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[1][i])
	{
		if (is_num(cmd, i))
			print_num_error(cmd->args[1]);
		i++;
	}
	if (!i)
		print_num_error(cmd->args[1]);
}

void	exit_cmd(t_cmd *cmd)
{
	int	error;
	int	res;

	error = 0;
	if (!cmd->args[1])
		ft_exit(g_all.cmd_error_status);
	check_is_num(cmd);
	check_too_many_arguments(cmd);
	res = ft_atoi(cmd->args[1], &error);
	if (error)
		print_num_error(cmd->args[1]);
	ft_exit(res);
}
