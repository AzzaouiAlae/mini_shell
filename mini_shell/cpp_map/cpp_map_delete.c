/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_map_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:22:22 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:22:23 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_func/ft_func.h"
#include "cpp_map.h"

void	cpp_map_delete(t_cpp_map *map, char *key)
{
	int			index;
	int			i;
	t_cs_list	**lists;
	t_key_value	**key_values;

	index = cpp_map_hash_function(key) % map->capacity;
	lists = map->content;
	if (!lists[index])
		return ;
	i = 0;
	while (lists[index]->count > i)
	{
		key_values = lists[index]->content;
		if (!ft_strcmp(key_values[i]->key, key))
		{
			cs_list_delete(lists[index], i);
			map->count--;
			return ;
		}
		i++;
	}
	return ;
}
