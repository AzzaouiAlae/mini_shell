/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:10 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 10:58:30 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	print_error(char *file_name, int *p_error)
{
	t_cpp_str	*str;

	if (!(*p_error))
		return ;
	*p_error = 0;
	str = cpp_str_new();
	cpp_str_add(str, "mini-shell: ");
	cpp_str_add(str, file_name);
	perror(str->content);
	g_all.cmd_error_status = 1;
}
