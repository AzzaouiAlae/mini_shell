/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:27:58 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/16 17:29:29 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int  check_pipe(t_token **token , int i)
{
    if(!i && token[i]->type & e_pipe && (token[i - 1]->type & (e_args | e_cmd))) 
    {
        return(0);
    }
}


int check_redir_in_out_in_first(t_token **token , int i)
{
    if (!i && token[i + 1] && !(token[i + 1]->type & e_file_name) )
    {
        
    }
}

// int check_redir(t_token **token , int i)
// {
//     int res;

//     res = g_all.tokens->count - 1 >= i + 1;
//     if (!i && token[i - 1]->type & e)
//     if(token[i + 1] && token[i]->type & e_redir_out_trun && !((token[i + 1]->type & e_file_name))) 
//     {
//         printf("Minishell : syntax error near unexpected token `>'\n");
//         g_all.cmd_error_status = 2;
//         return(0);
//     }
//     if(token[i + 1] && token[i]->type & e_redir_in && !((token[i + 1]->type & e_file_name))) 
//     {
//         printf("Minishell : syntax error near unexpected token `>'\n");
//         g_all.cmd_error_status = 2;
//         return(0);
//     }
//     return (1);
// }

void ft_check_syntax_error()
{
    t_token **token;
    int i;
    
    token = g_all.tokens->content;
    g_all.cmd_error_status = 0;
    i = 0;
    while (token[i])
    {
        
        i++;
    }
}