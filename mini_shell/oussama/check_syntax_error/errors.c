/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:15:26 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/16 18:31:17 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_syntax.h"

void print_redir_error (char *str)
{
    printf("Minishell : syntax error near unexpected token '%s'\n",str);
    g_all.cmd_error_status = 2;
}