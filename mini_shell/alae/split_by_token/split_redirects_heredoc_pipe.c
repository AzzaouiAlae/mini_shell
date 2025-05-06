/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirects_heredoc_pipe.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:22:03 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:22:04 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_shell.h"
#include "split_by_token.h"

int	is_redirects_heredoc(t_split_data *data)
{
	if (data->s[data->i] == '<' && data->s[data->i + 1] == '<')
	{
		g_all.token_str = cpp_str_new();
		cpp_str_add(g_all.token_str, "<<");
		data->type = e_heredoc;
		add_token(data);
		data->i += 2;
		return (1);
	}
	return (0);
}

int	is_redirects_input(t_split_data *data)
{
	if (data->s[data->i] == '<')
	{
		g_all.token_str = cpp_str_new();
		cpp_str_add(g_all.token_str, "<");
		data->type = e_redir_in;
		add_token(data);
		data->i++;
		return (1);
	}
	return (0);
}

int	is_redirects_out_append(t_split_data *data)
{
	if (data->s[data->i] == '>' && data->s[data->i + 1] == '>')
	{
		g_all.token_str = cpp_str_new();
		cpp_str_add(g_all.token_str, ">>");
		data->type = e_redir_out_app;
		add_token(data);
		data->i += 2;
		return (1);
	}
	return (0);
}

int	is_redirects_out_truncate(t_split_data *data)
{
	if (data->s[data->i] == '>')
	{
		g_all.token_str = cpp_str_new();
		cpp_str_add(g_all.token_str, ">");
		data->type = e_redir_out_trun;
		add_token(data);
		data->i++;
		return (1);
	}
	return (0);
}

int	is_pipe(t_split_data *data)
{
	if (data->s[data->i] == '|')
	{
		g_all.token_str = cpp_str_new();
		cpp_str_add(g_all.token_str, "|");
		data->type = e_pipe;
		add_token(data);
		data->i++;
		return (1);
	}
	return (0);
}
