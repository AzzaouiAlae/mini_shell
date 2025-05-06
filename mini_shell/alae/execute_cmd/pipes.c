/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:56 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:20:57 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmd.h"

t_pipe	*create_pipe(void)
{
	int		p[2];
	t_pipe	*_pipe;

	_pipe = ft_calloc(1, sizeof(t_pipe));
	if (pipe(p))
	{
		g_all.cmd_error_status = 1;
		_pipe->bad_fd = 1;
	}
	_pipe->fd_read = p[0];
	_pipe->fd_write = p[1];
	return (_pipe);
}

void	close_fd(t_exe_cmd_data *data)
{
	t_pipe	*p;
	int		i;

	i = 0;
	p = data->cmds[0]->pipe;
	while (p)
	{
		if (data->cmds[i]->input_fd)
			close(data->cmds[i]->input_fd);
		if (data->cmds[i]->output_fd)
			close(data->cmds[i]->output_fd);
		close(p->fd_read);
		close(p->fd_write);
		p = p->next;
		i++;
	}
	if (data->cmds[i] && data->cmds[i]->input_fd)
		close(data->cmds[i]->input_fd);
	if (data->cmds[i] && data->cmds[i]->output_fd)
		close(data->cmds[i]->output_fd);
}

void	dup_fd(t_exe_cmd_data *data)
{
	if (data->cmd->pipe && !data->i)
		dup2(data->cmd->pipe->fd_write, 1);
	else if (data->cmd->pipe && data->i)
	{
		if (data->cmd->pipe->next)
			dup2(data->cmd->pipe->next->fd_write, 1);
		dup2(data->cmd->pipe->fd_read, 0);
	}
	if (data->cmd->input_fd)
		dup2(data->cmd->input_fd, 0);
	if (data->cmd->output_fd)
		dup2(data->cmd->output_fd, 1);
	close_fd(data);
}

void	create_pipes(t_exe_cmd_data *data)
{
	if (data->c - 1 <= data->i || data->c == 1)
		return ;
	if (!data->i)
	{
		data->cmds[0]->pipe = create_pipe();
		data->cmds[1]->pipe = data->cmds[0]->pipe;
	}
	else
	{
		data->cmds[data->i]->pipe->next = create_pipe();
		data->cmds[data->i + 1]->pipe = data->cmds[data->i]->pipe->next;
	}
}
