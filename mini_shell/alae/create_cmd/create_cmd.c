#include "create_cmd.h"

void	add_fd_to_cmd(t_create_cmd *data)
{
	data->fd = *((int *)(data->tkn->s));
	if (data->tkn->type & e_heredoc_fd)
		data->cmd->heredoc_fd = data->fd;
	else if (data->tkn->type & e_redir_in_fd)
		data->cmd->redir_in_fd = data->fd;
	else if (data->tkn->type & e_redir_out_app_fd)
		data->cmd->redir_out_app_fd = data->fd;
	else if (data->tkn->type & e_redir_out_trun_fd)
		data->cmd->redir_out_trun_fd = data->fd;
}

char	*get_cmd_path(char *cmd_s)
{
	int			j;
	char		**paths;
	t_cpp_str	*str;
	t_cs_list	*ps;

	j = 0;
	ps = cpp_map_get(g_all.custom_env, "PATH");
	paths = ft_super_split(ps->content, ":", "");
	str = cpp_str_new();
	while (paths[j])
	{
		cpp_str_add(str, paths[j]);
		cpp_str_add_char(str, '/');
		cpp_str_add(str, cmd_s);
		if (!access(str->content, X_OK))
			return (str->content);
		cpp_str_clear(str);
		j++;
	}
	return (NULL);
}

void	add_cmd_token(t_create_cmd *data)
{
	if (data->tkn->type & e_path)
	{
		cs_list_add(data->cmd_args, (long)data->tkn->s);
		data->cmd->cmd_path = data->tkn->s;
	}
	else
	{
		cs_list_add(data->cmd_args, (long)data->tkn->s);
		data->cmd_path = get_cmd_path(data->tkn->s);
		if (data->cmd_path)
			data->cmd->cmd_path = data->cmd_path;
		else
			data->cmd->cmd_path = data->tkn->s;
	}
}

void	add_token_to_cmd(t_create_cmd *data)
{
	data->tkn = data->tkns[data->i];
	data->res_fd = (e_heredoc_fd | e_redir_in_fd | e_redir_out_app_fd | e_redir_out_trun_fd);
	if (data->tkn->type & e_pipe)
	{
		data->cmd->args = data->cmd_args->content;
		cs_list_add(g_all.cmds, (long)data->cmd);
		data->cmd = ft_calloc(1, sizeof(t_cmd));
        cs_list_clear(data->cmd_args);
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
		cs_list_add(g_all.cmds, (long)data.cmd);
	}
}
