/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:44:54 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/28 19:09:58 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "../mini_shell.h"

void	ft_exit(int num)
{
	ft_free_all();
	ft_close(g_all.terminal_fd);
	rl_clear_history();
	exit(num);
}

void	*current_working_mem(void *mem, int set_to_null)
{
	static void	*working_mem;

	if (set_to_null)
		working_mem = NULL;
	if (mem)
		working_mem = mem;
	return (working_mem);
}
