/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:26 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 11:05:19 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_env_var(t_key_value *kvp)
{
	t_cs_list	*value;

	value = kvp->value;
	if (value->type)
		printf("declare -x %s=\"%s\"\n", kvp->key, (char *)(value->content));
}

void	print_env_vars(void)
{
	cpp_map_foreach(g_all.custom_env, print_env_var);
}

void	print_export_vars_cmd(t_cmd *cmd)
{
	int	fd;

	add_vars_to_env();
	if (g_all.cmd_error_status || ft_strslen(cmd->args) > 1)
		return ;
	if (cmd && cmd->pipe)
	{
		fd = cmd->pipe->fd_write;
		dup2(fd, 1);
	}
	g_all.current_cmd = cmd;
	if (cmd && cmd->output_fd)
		dup2(cmd->output_fd, 1);
	if (cmd->args[1])
		return ;
	cpp_map_foreach(g_all.custom_env, print_env_var);
}
