/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:17:25 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/16 23:57:32 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_syntax.h"

int  check_pipe(t_token **token , int i)
{
    if(!i && token[i]->type & e_pipe && (token[i + 1] || !token[i + 1])) 
        return(print_redir_error("|"), 0);
    if(token[i + 1] && token[i]->type & e_pipe && (token[i + 1]->type & e_pipe))
        return(print_redir_error("|"), 0);
    return(1);
}


int check_redir_in_out_in_first(t_token **token , int i)
{
    if (token[i]->type & e_redir_out_trun && !token[i + 1])
        return(print_redir_error("newline"), 0);
    if (!i && token[i + 1] &&  token[i]->type & e_redir_out_trun && !(token[i + 1]->type & e_file_name))
        return(print_redir_error(token[i + 1]->s), 0);
    if (!i && token[i + 1] && token[i]->type & e_redir_in && !(token[i + 1]->type & e_file_name))
        return(print_redir_error(token[i + 1]->s), 0);
    if (!i && token[i + 1] &&  token[i]->type & e_redir_out_app && !(token[i + 1]->type & e_file_name))
        return(print_redir_error(token[i + 1]->s), 0);
    if (!i && token[i + 1] && token[i]->type & e_heredoc && !(token[i + 1]->type & e_file_name))
        return(print_redir_error(token[i + 1]->s), 0);
    return(1);
}

int check_redir(t_token **token , int i)
{
    int after_cmd, (berfor_cmd);

    berfor_cmd = (i > 0) && (e_args | e_pipe | e_file_name) & token[i - 1]->type;
    after_cmd = token[i + 1] &&  (e_file_name | e_set_var ) & token[i + 1]->type;
    if(token[i]->type & e_redir_out_trun && !berfor_cmd)
        return(print_redir_error(token[i - 1]->s), 0);
    else if(token[i]->type & e_redir_out_trun && !after_cmd)
        return(print_redir_error(token[i + 1]->s), 0);
    if(token[i]->type & e_redir_in && !berfor_cmd)
        return(print_redir_error(token[i - 1]->s), 0);
    else if(token[i]->type & e_redir_in && !after_cmd)
        return(print_redir_error(token[i + 1]->s), 0);
    if(token[i]->type & e_redir_out_app && !berfor_cmd)
        return(print_redir_error(token[i - 1]->s), 0);
    else if(token[i]->type & e_redir_out_app && !after_cmd)
        return(print_redir_error(token[i + 1]->s), 0);
    if(token[i]->type & e_redir_out_trun && !berfor_cmd)
        return(print_redir_error(token[i - 1]->s), 0);
    else if(token[i]->type & e_redir_out_trun && !after_cmd)
        return(print_redir_error(token[i + 1]->s), 0);
    return (1);
}

void ft_check_syntax_error()
{
//     t_token **token;
//     int i;
    
//     token = g_all.tokens->content;
//     g_all.cmd_error_status = 0;
//     i = 0;
//     while (token[i])
//     {
//         if (check_redir_in_out_in_first(token, i) == 0)
//             return ;
//         i++;
//     }
}