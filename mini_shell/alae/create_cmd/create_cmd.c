/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:55 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 23:06:13 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_cmd.h"

int	is_cmd_path(char *cmd_s, t_cpp_str *str, char **paths, int j)
{
	cpp_str_add(str, paths[j]);
	cpp_str_add_char(str, '/');
	cpp_str_add(str, cmd_s);
	if (!access(str->content, X_OK) && !is_dir(str->content))
		return (1);
	cpp_str_clear(str);
	return (0);
}

char	*get_cmd_path(char *cmd_s, t_create_cmd *data)
{
	int			j;
	char		**paths;
	t_cs_list	*ps;
	t_cpp_str	*str;

	j = 0;
	ps = cpp_map_get(g_all.custom_env, "PATH");
	str = cpp_str_new();
	if (ps)
		paths = ft_super_split(ps->content, ":", "");
	while (ps && paths && paths[j] && cmd_s[0])
	{
		if (is_cmd_path(cmd_s, str, paths, j))
			return (str->content);
		j++;
	}
	cpp_str_clear(str);
	cpp_str_add(str, cmd_s);
	if (ps)
		check_path(NULL, data, 0);
	else
		check_path(str->content, data, 1);
	return (str->content);
}

void	add_cmd_token(t_create_cmd *data)
{
	if (data->tkn->type & e_path || is_path(data->tkn->s)
		|| cpp_map_get(g_all.builtins, data->tkn->s))
	{
		check_path(data->tkn->s, data, 1);
		cs_list_add(data->cmd_args, (long)data->tkn->s);
		data->cmd->cmd_path = data->tkn->s;
	}
	else
	{
		cs_list_add(data->cmd_args, (long)data->tkn->s);
		data->cmd_path = get_cmd_path(data->tkn->s, data);
		data->cmd->cmd_path = data->cmd_path;
	}
}

void	add_token_to_cmd(t_create_cmd *data)
{
	data->tkn = data->tkns[data->i];
	data->res_fd = (e_heredoc_fd | e_redir_in_fd | e_redir_out_app_fd
			| e_redir_out_trun_fd);
	if (data->tkn->type & e_pipe)
	{
		data->cmd->args = data->cmd_args->content;
		if (data->cmd_not_found)
			data->cmd->cmd_path = NULL;
		cs_list_add(g_all.cmds, (long)data->cmd);
		data->cmd = ft_calloc(1, sizeof(t_cmd));
		data->cmd_args = cs_list_new(sizeof(char *));
		data->cmd_not_found = 0;
	}
	else if (data->tkn->type & data->res_fd)
		add_fd_to_cmd(data);
	else if (data->tkn->type & e_cmd)
		add_cmd_token(data);
	else
		cs_list_add(data->cmd_args, (long)data->tkn->s);
}

void	create_cmd(void)
{
	t_create_cmd	data;

	ft_bzero(&data, sizeof(t_create_cmd));
	g_all.cmds = cs_list_new(sizeof(t_cmd *));
	data.tkns = g_all.tokens->content;
	data.cmd = ft_calloc(1, sizeof(t_cmd));
	data.cmd_args = cs_list_new(sizeof(char *));
	while (data.tkns[data.i])
	{
		add_token_to_cmd(&data);
		data.i++;
	}
	if (data.i)
	{
		data.cmd->args = data.cmd_args->content;
		if (data.cmd_not_found)
			data.cmd->cmd_path = NULL;
		cs_list_add(g_all.cmds, (long)data.cmd);
	}
}
