/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:23:56 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/13 21:00:08 by aazzaoui         ###   ########.fr       */
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

void	init_input(void)
{
	g_all.is_error_printed = 0;
	g_all.cmd_error_status = 0;
	init_new_env();
}

void	free_cmd(t_cmd *cmd, int j)
{
	int	i;
	int	free_cmd;

	i = 0;
	free_cmd = 1;
	if (cmd->args[i] == cmd->cmd_path)
		free_cmd = 0;
	while (cmd->args && cmd->args[i])
	{
		ft_free(cmd->args[i]);
		i++;
	}
	ft_free(cmd->args);
	if (free_cmd)
		ft_free(cmd->cmd_path);
	if (j)
		ft_free(cmd->pipe);
	ft_free(cmd);
}

void	clean_cmd(void)
{
	t_token	**tokens;
	t_cmd	**cmds;
	int		i;

	i = 0;
	set_exit_status();
	last_arg(0);
	delete_files(1);
	tokens = g_all.tokens->content;
	while (tokens && i < g_all.tokens->count)
	{
		ft_free(tokens[i]);
		i++;
	}
	if (!g_all.cmds)
		return ;
	cmds = g_all.cmds->content;
	i = 0;
	while (i < g_all.cmds->count)
	{
		free_cmd(cmds[i], i);
		i++;
	}
	cs_list_clear(g_all.tokens);
	cs_list_clear(g_all.cmds);
}

void	process_cmd(char *s)
{
	init_input();
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
	clean_cmd();
}
