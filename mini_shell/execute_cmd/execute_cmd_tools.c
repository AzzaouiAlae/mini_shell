/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 05:23:54 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 16:37:07 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmd.h"

void	sig_quit(int signo)
{
	(void)signo;
	write(1, "Quit (core dumped)\n", 20);
}

void	close_fd_parent(t_exe_cmd_data *data)
{
	int		i;
	t_pipe	*p;

	i = 0;
	if (data->cmds[data->i]->input_fd)
		ft_close(data->cmds[data->i]->input_fd);
	if (data->cmds[data->i]->output_fd)
		ft_close(data->cmds[data->i]->output_fd);
	if (!data->i)
		return ;
	p = data->cmds[0]->pipe;
	while (data->i - 1 > i && p->next)
	{
		p = p->next;
		i++;
	}
	if (p)
	{
		ft_close(p->fd_read);
		p->fd_read = -1;
		ft_close(p->fd_write);
		p->fd_write = -1;
	}
}
