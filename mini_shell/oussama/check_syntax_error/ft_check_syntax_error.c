/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:17:25 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/18 22:38:37 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_syntax.h"

int  check_pipe(t_token **token , int i)
{
    if(!i && token[i]->type & e_pipe && (token[i + 1] || !token[i + 1])) 
        return(print_redir_error("|"), 0);
    if(token[i + 1] && token[i]->type & e_pipe && (token[i + 1]->type & e_pipe))
        return(print_redir_error("|"), 0);
    if(token[i]->type & e_pipe && !token[i + 1])
        return(print_redir_error("HERDOC TATCHOFHA ALAA"), 0);
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
    int after_cmd, (berfor_cmd), (last);

    berfor_cmd = (i > 0) && (e_args | e_pipe | e_file_name) & token[i - 1]->type;
    after_cmd = token[i + 1] && (e_file_name | e_set_var ) & token[i + 1]->type;
    last = (e_redir_out_app | e_redir_out_trun | e_redir_in | e_heredoc) & token[i]->type;
    if (last && !token[i + 1])
        return(print_redir_error("newline"), 0);
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
    if(token[i]->type & e_heredoc && !berfor_cmd)
        return(print_redir_error(token[i - 1]->s), 0);
    else if(token[i]->type & e_heredoc && !after_cmd)
        return(print_redir_error(token[i + 1]->s), 0);
    return (1);
}

int ft_check_syntax_error()
{
    t_token **tokens;
    int i;
    
    tokens = g_all.tokens->content;
    g_all.cmd_error_status = 0;
    i = 0;
    while (tokens[i])
    {
        if (check_redir_in_out_in_first(tokens, i) == 0)
            return (0);
        if (check_redir(tokens, i) == 0)
            return(0);
        if (check_pipe(tokens, i) == 0)
            return(0);
        i++;
    }
    return(1);
}

// ----------------- RAH SALIT HANJI SBAH NDIR LES TESTS LHADCHI BACH NCHOFO CHI HAJA KHRA ---------------------



// int main ()
// {
//     printf("return %d && status[%d]\n", ft_check_syntax_error(), g_all.cmd_error_status);
// }
