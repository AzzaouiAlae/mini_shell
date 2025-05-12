/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:17:25 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 15:35:26 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"
#include "ft_check_syntax.h"

int	check_pipe(t_token **token, int i)
{
	if (!i && token[i]->type & e_pipe && (token[i + 1] || !token[i + 1]))
		return (print_redir_error("|"), 0);
	if (token[i + 1] && token[i]->type & e_pipe
		&& (token[i + 1]->type & e_pipe))
		return (print_redir_error("|"), 0);
	if (token[i]->type & e_pipe && !token[i + 1])
		return (print_redir_error("newline"), 0);
	return (1);
}

int	check_redir_in_out_in_first(t_token **token, int i)
{
	if (token[i]->type & e_redir_out_trun && !token[i + 1])
		return (print_redir_error("newline"), 0);
	if (!i && token[i + 1] && token[i]->type & e_redir_out_trun
		&& !(token[i + 1]->type & e_file_name))
		return (print_redir_error(token[i + 1]->s), 0);
	if (!i && token[i + 1] && token[i]->type & e_redir_in
		&& !(token[i + 1]->type & e_file_name))
		return (print_redir_error(token[i + 1]->s), 0);
	if (!i && token[i + 1] && token[i]->type & e_redir_out_app
		&& !(token[i + 1]->type & e_file_name))
		return (print_redir_error(token[i + 1]->s), 0);
	if (!i && token[i + 1] && token[i]->type & e_heredoc
		&& !(token[i + 1]->type & e_delimiter))
		return (print_redir_error(token[i + 1]->s), 0);
	return (1);
}

int	check_redir(t_token **token, int i)
{
	int after_cmd, (last);
	after_cmd = token[i + 1]
		&& (e_file_name | e_set_var | e_delimiter) & token[i + 1]->type;
	last = (e_redir_out_app | e_redir_out_trun | e_redir_in | e_heredoc)
		& token[i]->type;
	if (last && !token[i + 1])
		return (print_redir_error("newline"), 0);
	else if (token[i]->type & e_redir_out_trun && !after_cmd)
		return (print_redir_error(token[i + 1]->s), 0);
	else if (token[i]->type & e_redir_in && !after_cmd)
		return (print_redir_error(token[i + 1]->s), 0);
	else if (token[i]->type & e_redir_out_app && !after_cmd)
		return (print_redir_error(token[i + 1]->s), 0);
	else if (token[i]->type & e_heredoc && !after_cmd)
		return (print_redir_error(token[i + 1]->s), 0);
	return (1);
}

int	ft_check_syntax_error(void)
{
	t_token	**tokens;

	tokens = g_all.tokens->content;
	g_all.cmd_error_status = 0;
	g_all.error_i = 0;
	while (tokens[g_all.error_i])
	{
		if (check_redir_in_out_in_first(tokens, g_all.error_i) == 0)
			return (0);
		if (check_redir(tokens, g_all.error_i) == 0)
			return (0);
		if (check_pipe(tokens, g_all.error_i) == 0)
			return (0);
		g_all.error_i++;
	}
	return (1);
}
