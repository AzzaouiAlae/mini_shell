/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:26 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 22:54:23 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_env_var(t_key_value *kvp)
{
	t_cs_list	*value;

	value = kvp->value;
	if (value->type == e_global_var && value->content)
		printf("declare -x %s=\"%s\"\n", kvp->key, (char *)(value->content));
	else if (value->type == e_global_var)
		printf("declare -x %s=\n", kvp->key);
	else if (value->type == e_export_var)
		printf("declare -x %s\n", kvp->key);
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
