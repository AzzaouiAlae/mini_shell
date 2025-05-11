/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redirection_files.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:04 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/10 22:37:31 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	get_open_permission(int type)
{
	if (type & e_redir_in)
		return (O_RDONLY);
	if (type & e_redir_out_app)
		return (O_APPEND | O_CREAT | O_WRONLY);
	if (type & e_redir_out_trun)
		return (O_TRUNC | O_CREAT | O_WRONLY);
	return (0);
}

int	get_type(int type)
{
	if (type & e_redir_in)
		return (e_redir_in_fd);
	if (type & e_redir_out_app)
		return (e_redir_out_app_fd);
	if (type & e_redir_out_trun)
		return (e_redir_out_trun_fd);
	return (0);
}

void	open_file(t_token **tokens, int i, int *fd, int *p_error)
{
	int	open_perm;

	if (!(*p_error))
	{
		*fd = -1;
		return ;
	}
	open_perm = get_open_permission(tokens[i]->type);
	*fd = ft_open(tokens[i + 1]->s, open_perm, 0666);
	if (*fd == -1)
		print_error(tokens[i + 1]->s, p_error);
	if (tokens[i]->type & (e_redir_out_app | e_redir_out_trun))
		dup2(*fd, 1);
}

void	open_redirection_file(t_token **tokens, int i, int *p_error)
{
	int		fd;
	t_token	*token;

	if (!tokens[i + 1])
	{
		cs_list_delete(g_all.tokens, i);
		return ;
	}
	open_file(tokens, i, &fd, p_error);
	token = ft_calloc(1, sizeof(t_token));
	token->s = ft_calloc(1, sizeof(int));
	*((int *)(token->s)) = fd;
	token->type = get_type(tokens[i]->type);
	cs_list_delete(g_all.tokens, i);
	cs_list_delete(g_all.tokens, i);
	cs_list_inset_at(g_all.tokens, i, (long)token);
}

void	open_redirection_files(void)
{
	t_token	**tokens;
	int		i;
	int		old_fd;
	int		p_error;

	i = 0;
	p_error = 1;
	old_fd = dup(1);
	tokens = g_all.tokens->content;
	while (g_all.tokens->count > i)
	{
		if (tokens[i]->type & (e_redir_in | e_redir_out_app | e_redir_out_trun))
			open_redirection_file(tokens, i, &p_error);
		if (g_all.tokens->count && tokens[i]->type & e_pipe)
		{
			p_error = 1;
			dup2(old_fd, 1);
		}
		i++;
	}
	dup2(old_fd, 1);
	ft_close(old_fd);
}
