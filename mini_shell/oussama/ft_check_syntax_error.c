/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:27:58 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/15 21:54:10 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int  check_pipe(t_token token , int i)
{
    if(!i && token.type & e_pipe)
    {
        return(0);
    }
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
        
        i++;
    }
}