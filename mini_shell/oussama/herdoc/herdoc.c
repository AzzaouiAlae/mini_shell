/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:16:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/27 17:57:28 by oel-bann         ###   ########.fr       */
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

char *here_doc(t_token **tokens, int i, int expand_her)
{
    int fd;
	t_her_doc *her_doc;
	
	her_doc = ft_calloc(1, sizeof(t_her_doc));
	str = readline("$>: ");
	limiter = tokens[i + 1]->s;
	while (ft_strncmp(limiter, str, ft_strlen(limiter)) != 0)
	{
        if (!str)
        {
			printf("warning: here-document at line %d ", g_all.i);
            printf("delimited by end-of-file (wanted `%s')", limiter);
            ft_exit(0);
        }
        if (expand_her)
            expand_str = get_env_vars_heredoc(str);
        else
            expand_str = str;
		write(fd, expand_str, ft_strlen(expand_str));
		write(fd, "\n", 1);
		free(str);
		str = readline("$>: ");
	}
	free(str);
	return (file_name);
}


// int main() {
//     // Initialize global state
//     g_all = (t_global){0};

//     // Create test tokens: << EOF with variable expansion
//     t_token **tokens = malloc(sizeof(t_token*) * 3);
    
//     tokens[0] = malloc(sizeof(t_token));
//     tokens[0]->s = "<<";
//     tokens[0]->type = e_heredoc | e_var_to_get;
    
//     tokens[1] = malloc(sizeof(t_token));
//     tokens[1]->s = "EOF";
//     tokens[1]->type = e_delimiter;
    
//     tokens[2] = NULL;

//     // Add tokens to global list
//     t_cs_list *token_list = cs_list_new(sizeof(t_cs_list));
//     token_list->content = tokens;
//     g_all.tokens = token_list;
//     // Test the heredoc functionality
//     check_here_doc();
//     return 0;
// }