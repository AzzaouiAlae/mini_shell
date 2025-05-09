/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:42 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 11:45:29 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_cmd.h"

void	add_input_fd(t_create_cmd *data)
{
	if (data->cmd->input_fd > 0)
		ft_close(data->cmd->input_fd);
	if (data->fd != 0 && data->cmd->input_fd != -1)
		data->cmd->input_fd = data->fd;
}

void	add_output_fd(t_create_cmd *data)
{
	if (data->cmd->output_fd)
		ft_close(data->cmd->output_fd);
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
