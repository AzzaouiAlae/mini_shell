/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:23:56 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/09 16:19:26 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	last_arg(int is_child)
{
	int			i;
	t_cmd		*cmd;
	t_cs_list	*value;

	if ((!g_all.cmds || g_all.cmds->count != 1) && !is_child)
		return ;
	i = 0;
	cmd = ((t_cmd **)(g_all.cmds->content))[g_all.cmds->count - 1];
	if (is_child)
		cmd = ((t_cmd **)(g_all.cmds->content))[0];
	if (!(cmd->args) || !(cmd->args[0]))
		return ;
	value = cs_list_new(sizeof(char));
	while (value && cmd && cmd->args && cmd->args[i])
		i++;
	value->type = e_global_var;
	cs_list_add_range(value, ft_strlen(cmd->args[i - 1]), cmd->args[i - 1]);
	cpp_map_add(g_all.custom_env, "_", value);
}

void	process_cmd(char *s)
{
	g_all.is_error_printed = 0;
	init_new_env();
	g_all.cmd_error_status = 0;
	split_tokens(replace_char(ft_strdup(s), '\n', '\0'), " |<>\t$", "\"'");
	if (!g_all.cmd_error_status)
	{
		ft_check_syntax_error();
		check_here_doc(s);
		if (!g_all.cmd_error_status)
		{
			get_variables_value();
			ft_check_syntax_after_pars();
			if (!g_all.cmd_error_status)
			{
				rm_single_double_qoute();
				open_redirection_files();
				create_cmd();
				cpp_map_foreach(g_all.custom_env, add_env);
				execute_cmd();
			}
		}
	}
	set_exit_status();
	last_arg(0);
	delete_files(1);
}
