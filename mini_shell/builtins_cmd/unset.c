/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:33 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:18:34 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	unset(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->args && cmd->args[i])
	{
		cpp_map_delete(g_all.custom_env, cmd->args[i]);
		i++;
	}
}
