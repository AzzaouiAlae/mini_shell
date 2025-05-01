/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:16:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/01 09:16:19 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

int count_here_doc()
{
	t_token **tokens;
    int herdoc_count, (i) = 0;

	herdoc_count = 0;
    tokens = g_all.tokens->content;
	while(tokens[i] && i < g_all.error_i)
	{
        if (tokens[i + 1] && (tokens[i]->type & e_heredoc) && (tokens[i + 1]->type & e_delimiter))
			herdoc_count++;
		i++;
	}
	return (herdoc_count);
}

char *get_line(char *input, int flag)
{
	static int fd;

	if (flag)
	{
		fd = open("./temp.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
		if (fd == -1)
			return(NULL);
		write(fd, input, ft_strlen(input));
		close(fd);
		fd = open("./temp.txt", O_RDWR, 0666);
		get_next_line(fd);
	}
	else if (flag == 2)
		unlink("./temp.txt");
	else
		return(get_next_line(fd));
	return(NULL);
}

void check_here_doc(char *input)
{
	t_token **tokens;
    int (i) = 0;
    
    tokens = g_all.tokens->content;
	if (count_here_doc() > 16)
	{
		g_all.cmd_error_status = 2;
		write(2, "Minishell: maximum here-document count exceeded\n",48);
		return;
	}
	get_line(input, 1);    
	while(tokens[i] && i < g_all.error_i)
	{
        if (tokens[i + 1] && (tokens[i]->type & e_heredoc) && (tokens[i + 1]->type & e_delimiter))
        {
            if (tokens[i]->type & e_var_to_get)
			    here_doc(tokens, i, 1);
		    else
			    here_doc(tokens, i, 0);
        }
		// else if (tokens[i + 1] && (tokens[i]->type & e_heredoc) && !(tokens[i + 1]->type & e_delimiter))
		// {
		// 	if (!tokens[i + 1])
		// 		print_redir_error("newline");
		// 	else
		// 		print_redir_error(tokens[i + 1]->s);
		// 	return;
		// }
		i++;
	}
	get_line(NULL, 2);
}

int create_here_doc_file(t_her_doc *her_doc)
{
	her_doc->file_name = create_file_name();
    cs_list_add(g_all.files_to_remove, (long)her_doc->file_name);
	her_doc->fd = open(her_doc->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (her_doc->fd == -1)
	{
		g_all.cmd_error_status = 127;
		write(2, "ERROR HERDOC FILE CAN'T OPEN\n", 29);
		return(0);
	}
	return (1);
}

int get_her_doc_line (t_her_doc *her_doc)
{
	if (!her_doc->str)
    {
		printf("warning: here-document at line %d ", g_all.i);
        printf("delimited by end-of-file (wanted `%s')\n", her_doc->limiter);
        g_all.cmd_error_status = 0;
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

void rem_delimitter_and_heredoc(int i, int fd)
{
	t_token *token;
	
	token = ft_calloc(1, sizeof(t_token));
    token->s = ft_calloc(1, sizeof(int));
	token->type = e_heredoc_fd;
    *((int *)(token->s)) = fd;
	cs_list_inset_at(g_all.tokens, i,(long)token);
	cs_list_delete(g_all.tokens, i + 1);
	cs_list_delete(g_all.tokens, i + 1);
}

void here_doc(t_token **tokens, int i, int expand_her)
{
	t_her_doc her_doc;
	char *(*input) = NULL;
	ft_bzero(&her_doc, sizeof(t_her_doc));
	if (create_here_doc_file(&her_doc) == 0)
		return;
	her_doc.str = get_line(NULL, 0);
	if (!her_doc.str)
		her_doc.str = readline("> ");
	her_doc.limiter = tokens[i + 1]->s;
	her_doc.expand_her = expand_her;
	while (ft_strncmp(her_doc.limiter, her_doc.str, ft_strlen(her_doc.limiter) + 1) != 0)
	{
		add_new_cmd_history(her_doc.str, 0);
		if (get_her_doc_line (&her_doc) == 0)
			return;
		free(her_doc.str);
		g_all.i++;
		her_doc.str = get_line(NULL, 0);
		if (!her_doc.str)
			her_doc.str = readline("> ");
	}
	add_new_cmd_history(her_doc.str, 0);
	free(her_doc.str);
	rem_delimitter_and_heredoc(i, her_doc.fd);
}
/*
history
cmd
new_file_file
*/