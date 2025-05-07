/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:42 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/07 22:42:43 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_cmd.h"

void	add_input_fd(t_create_cmd *data)
{
	if (data->cmd->input_fd > 0)
		close(data->cmd->input_fd);
	if (data->fd != 0 && data->cmd->input_fd != -1)
		data->cmd->input_fd = data->fd;
}

void	add_output_fd(t_create_cmd *data)
{
	if (data->cmd->output_fd)
		close(data->cmd->output_fd);
	if (data->fd != 0 && data->cmd->output_fd != -1)
		data->cmd->output_fd = data->fd;
}

void	add_fd_to_cmd(t_create_cmd *data)
{
	data->fd = *((int *)(data->tkn->s));
	if (data->tkn->type & e_heredoc_fd)
		add_input_fd(data);
	else if (data->tkn->type & e_redir_in_fd)
		add_input_fd(data);
	else if (data->tkn->type & e_redir_out_app_fd)
		add_output_fd(data);
	else if (data->tkn->type & e_redir_out_trun_fd)
		add_output_fd(data);
}
