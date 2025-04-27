/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:16:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/27 19:40:49 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

void check_here_doc()
{
	t_token **tokens;
    int i;
    
    tokens = g_all.tokens->content;
    g_all.cmd_error_status = 0;
    i = 0;
	while(tokens[i])
	{
        if ((tokens[i]->type & e_heredoc) && tokens[i + 1])
        {
            if (tokens[i]->type & e_var_to_get)
			    here_doc(tokens, i, 1);
		    else
			    here_doc(tokens, i, 0);
        }		
		i++;
	}
}

int create_here_doc_file(t_her_doc *her_doc)
{
	her_doc->file_name = create_file_name();
    cs_list_add(g_all.files_to_remove, her_doc->file_name);
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
        printf("delimited by end-of-file (wanted `%s')", her_doc->limiter);
        g_all.cmd_error_status = 0;
		return (0);
    }
    if (her_doc->expand_her)
        her_doc->expand_str = get_env_vars_heredoc(her_doc->str);
    else
        her_doc->expand_str = her_doc->str;
	write(her_doc->fd, her_doc->expand_str, ft_strlen(her_doc->str));
	write(her_doc->fd, "\n", 1);
	return (1);
}

int here_doc(t_token **tokens, int i, int expand_her)
{
	t_her_doc *her_doc;
	
	her_doc = ft_calloc(1, sizeof(t_her_doc));
	if (create_here_doc_file(her_doc) == 0)
		return (0);
	her_doc->str = readline("> ");
	her_doc->limiter = tokens[i + 1]->s;
	her_doc->expand_her = expand_her;
	while (ft_strncmp(her_doc->limiter, her_doc->str, ft_strlen(her_doc->limiter)) != 0)
	{
		if (get_her_doc_line (her_doc) == 0)
			return (0);
		free(her_doc->str);
		her_doc->str = readline("> ");
	}
	free(her_doc->str);
	return (1);
}
