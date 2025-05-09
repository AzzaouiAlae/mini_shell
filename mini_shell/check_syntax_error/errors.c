/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:15:26 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/08 05:35:25 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"
#include "ft_check_syntax.h"

void	print_redir_error(char *str)
{
	write(2, "Minishell : syntax error near unexpected token `", 48);
	write(2, str, ft_strlen(str));
	write(2, "'\n", 2);
	g_all.cmd_error_status = 2;
}
