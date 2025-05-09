/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_map_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:22:10 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 10:43:37 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_func/ft_func.h"
#include "cpp_map.h"

int	add_item_to_list(t_key_value **kvps, int count, t_key_value *kvp)
{
	int	i;

	i = 0;
	while (count > i)
	{
		if (!ft_strcmp(kvps[i]->key, kvp->key))
		{
			kvps[i]->value = kvp->value;
			return (0);
		}
		i++;
	}
	return (1);
}

void	add_item(t_cpp_map *map, t_cs_list **lists, t_key_value *kvp, int i)
{
	t_key_value	**kvps;

	if (lists[i])
	{
		kvps = lists[i]->content;
		if (add_item_to_list(kvps, lists[i]->count, kvp))
		{
			cs_list_add(lists[i], (long)kvp);
			map->count++;
		}
	}
	else
	{
		lists[i] = cs_list_new_capacity(sizeof(t_key_value *), 4);
		cs_list_add(lists[i], (long)kvp);
		map->count++;
	}
}

void	cpp_map_add(t_cpp_map *map, char *key, void *value)
{
	int			index;
	t_key_value	*kvp;
	t_cs_list	**lists;

	if (map->count > map->max_size)
		cpp_map_resize(map, next_prime(map->capacity * 2));
	lists = map->content;
	kvp = ft_calloc(1, sizeof(t_key_value));
	kvp->key = key;
	kvp->value = value;
	index = cpp_map_hash_function(key) % map->capacity;
	add_item(map, lists, kvp, index);
}
