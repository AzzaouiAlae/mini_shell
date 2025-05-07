/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:16:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/07 23:02:16 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

int	count_here_doc(void)
{
	t_token	**tokens;

	int herdoc_count, (i) = 0;
	herdoc_count = 0;
	tokens = g_all.tokens->content;
	while (tokens[i] && i < g_all.error_i)
	{
		if (tokens[i + 1] && (tokens[i]->type & e_heredoc) && (tokens[i
				+ 1]->type & e_delimiter))
			herdoc_count++;
		i++;
	}
	return (herdoc_count);
}

char	*get_line(char *input, int flag)
{
	static int	fd;

	if (flag == 1)
	{
		fd = open("./temp.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
		if (fd == -1)
			return (NULL);
		write(fd, input, ft_strlen(input));
		close(fd);
		fd = open("./temp.txt", O_RDWR, 0666);
		get_next_line(fd);
	}
	else if (flag == 2)
	{
		close(fd);
		unlink("./temp.txt");
	}
	else
		return (get_next_line(fd));
	return (NULL);
}

void	check_here_doc(char *input)
{
	t_token	**tokens;

	int(i) = 0;
	tokens = g_all.tokens->content;
	if (count_here_doc() > 16)
	{
		g_all.cmd_error_status = 2;
		write(2, "Minishell: maximum here-document count exceeded\n", 48);
		return ;
	}
	get_line(input, 1);
	while (tokens[i] && i < g_all.error_i)
	{
		if (tokens[i + 1] && (tokens[i]->type & e_heredoc) && (tokens[i
				+ 1]->type & e_delimiter))
		{
			if (tokens[i]->type & e_var_to_get)
				here_doc(tokens, i, 1);
			else
				here_doc(tokens, i, 0);
		}
		i++;
	}
	get_line(NULL, 2);
}

int	create_here_doc_file(t_her_doc *her_doc)
{
	her_doc->file_name = create_file_name();
	cs_list_add(g_all.files_to_remove, (long)her_doc->file_name);
	her_doc->fd = open(her_doc->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (her_doc->fd == -1)
	{
		g_all.cmd_error_status = 127;
		write(2, "ERROR HERDOC FILE CAN'T OPEN\n", 29);
		return (0);
	}
	return (1);
}
void	rem_delimitter_and_heredoc(int i, int fd, char *file_name)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->s = ft_calloc(1, sizeof(int));
	token->type = e_heredoc_fd;
	close(fd);
	fd = open(file_name, O_RDONLY, 0666);
	if (fd == -1)
	{
		g_all.cmd_error_status = 127;
		write(2, "ERROR HERDOC FILE CAN'T OPEN\n", 29);
		return ;
	}
	*((int *)(token->s)) = fd;
	cs_list_inset_at(g_all.tokens, i, (long)token);
	cs_list_delete(g_all.tokens, i + 1);
	cs_list_delete(g_all.tokens, i + 1);
}

int	get_her_doc_line(t_her_doc *her_doc, int i)
{
	t_cpp_str *str;
	
	if (!her_doc->str)
	{
		str = ft_itoa(g_all.i);
		cpp_str_insert(str, "Minishell: warning: here-document at line ", 0);
		cpp_str_add(str, " delimited by end-of-file (wanted `");
		cpp_str_add(str, her_doc->limiter);
		cpp_str_add(str, "')\n");
		write(2, str->content, str->count);
		g_all.cmd_error_status = 0;
		rem_delimitter_and_heredoc(i, her_doc->fd, her_doc->file_name);
		return (0);
	}
	if (her_doc->expand_her)
		her_doc->expand_str = get_env_vars_heredoc(her_doc->str);
	else
		her_doc->expand_str = her_doc->str;
	write(her_doc->fd, her_doc->expand_str, ft_strlen(her_doc->expand_str));
	write(her_doc->fd, "\n", 1);
	return (1);
}



void	here_doc(t_token **tokens, int i, int expand_her)
{
	t_her_doc	her_doc;

	ft_bzero(&her_doc, sizeof(t_her_doc));
	if (create_here_doc_file(&her_doc) == 0)
		return ;
	her_doc.str = replace_char(get_line(NULL, 0), '\n', '\0');
	if (!her_doc.str)
	{
		her_doc.str = get_next_line(0);
		if (ft_strlen(her_doc.str))
			her_doc.str[ft_strlen(her_doc.str) - 1] = '\0';
	}
	// her_doc.str = readline("> ");
	her_doc.limiter = tokens[i + 1]->s;
	her_doc.expand_her = expand_her;
	while (ft_strncmp(her_doc.limiter, her_doc.str, ft_strlen(her_doc.limiter)
			+ 1) != 0)
	{
		add_new_cmd_history(her_doc.str, 0);
		if (get_her_doc_line(&her_doc, i) == 0)
			return ;
		ft_free(her_doc.str);
		g_all.i++;
		her_doc.str = replace_char(get_line(NULL, 0), '\n', '\0');
		if (!her_doc.str)
		{
			her_doc.str = get_next_line(0);
			if (ft_strlen(her_doc.str))
				her_doc.str[ft_strlen(her_doc.str) - 1] = '\0';
		}
		// her_doc.str = readline("> ");
	}
	add_new_cmd_history(her_doc.str, 0);
	ft_free(her_doc.str);
	rem_delimitter_and_heredoc(i, her_doc.fd, her_doc.file_name);
}
/*
history
cmd
new_file_file
*/