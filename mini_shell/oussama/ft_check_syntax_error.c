/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:27:58 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/16 21:41:29 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_syntax.h"

int  check_pipe(t_token **token , int i)
{
    if(!i && token[i]->type & e_pipe && (token[i - 1]->type & (e_args | e_cmd))) 
    {
        
    }
}


int check_redir_in_out_in_first(t_token **token , int i)
{
    // if (token[i]->type & e_redir_out_trun && !token[i + 1])
    //     return(print_redir_error("newline"), 0);
    // if (!i && token[i + 1] &&  token[i]->type & e_redir_out_trun && !(token[i + 1]->type & e_file_name))
    //     return(print_redir_error(token[i + 1]), 0);
    // if (!i && token[i + 1] && token[i]->type & e_redir_in && !(token[i + 1]->type & e_file_name))
    //     return(print_redir_error(token[i + 1]), 0);
    // if (!i && token[i + 1] &&  token[i]->type & e_redir_out_app && !(token[i + 1]->type & e_file_name))
    //     return(print_redir_error(token[i + 1]), 0);
    // if (!i && token[i + 1] && token[i]->type & e_heredoc && !(token[i + 1]->type & e_file_name))
    //     return(print_redir_error(token[i + 1]), 0);
    return(1);
}

int check_redir(t_token **token , int i)
{
    int res;

    res = g_all.tokens->count - 1 >= i + 1;
    //if (!i && token[i - 1]->type & e)
    if(token[i + 1] && token[i]->type & e_redir_out_trun && !((token[i + 1]->type & e_file_name))) 
    {
        printf("Minishell : syntax error near unexpected token `>'\n");
        g_all.cmd_error_status = 2;
        return(0);
    }
    if(token[i + 1] && token[i]->type & e_redir_in && !((token[i + 1]->type & e_file_name))) 
    {
        printf("Minishell : syntax error near unexpected token `>'\n");
        g_all.cmd_error_status = 2;
        return(0);
    }
    return (1);
}

void ft_check_syntax_error()
{
    t_token **token;
    int i;
    
    token = g_all.tokens->content;
    g_all.cmd_error_status = 0;
    i = 0;
    while (token[i])
    {
        if (check_redir_in_out_in_first(token, i) == 0)
            return ;
        i++;
    }
}