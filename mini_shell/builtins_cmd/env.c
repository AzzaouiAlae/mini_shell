/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:19 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 11:03:05 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../create_cmd/create_cmd.h"
#include "builtins.h"

void	print_env(t_key_value *kvp)
{
	t_cs_list	*value;

	value = kvp->value;
	if (value->type)
		printf("%s=%s\n", kvp->key, (char *)(value->content));
}

void	env(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i > 1)
		ft_exit(0);
	cpp_map_foreach(g_all.custom_env, print_env);
}
