/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:17:59 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 23:08:12 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_builtin(char *cmd)
{
	if (cpp_map_get(g_all.builtins, cmd))
		return (1);
	return (0);
}

void	run_builtin_cmds(void)
{
	int		i;
	t_cmd	**cmds;
	void	(*cmd)(t_cmd *c);

	i = 0;
	cmds = g_all.cmds->content;
	while (i < g_all.cmds->count)
	{
		cmd = cpp_map_get(g_all.builtins, cmds[i]->cmd_path);
		if (cmd)
			cmd(cmds[i]);
		i++;
	}
}

void	init_builtins_map(void)
{
	g_all.builtins = cpp_map_new();
	cpp_map_add(g_all.builtins, "export", print_export_vars_cmd);
	cpp_map_add(g_all.builtins, "echo", echo);
	cpp_map_add(g_all.builtins, "cd", cd);
	cpp_map_add(g_all.builtins, "pwd", pwd);
	cpp_map_add(g_all.builtins, "unset", unset);
	cpp_map_add(g_all.builtins, "env", env);
	cpp_map_add(g_all.builtins, "exit", exit_cmd);
}
