/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:22:41 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:22:42 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpp_map.h"

void	add_list_to_new_map(t_cpp_map *map, t_cs_list *list)
{
	t_key_value	**kvps;
	int			i;

	kvps = list->content;
	i = 0;
	while (i < list->count)
	{
		cpp_map_add(map, kvps[i]->key, kvps[i]->value);
		i++;
	}
}

void	cpp_map_resize(t_cpp_map *map, int capacity)
{
	int			old_capacity;
	t_cs_list	**lists;
	int			i;

	i = 0;
	lists = map->content;
	old_capacity = map->capacity;
	map->capacity = capacity;
	map->max_size = (double)map->capacity * .70;
	map->content = ft_calloc(map->capacity, sizeof(void *));
	map->count = 0;
	while (i < old_capacity)
	{
		if (lists[i])
			add_list_to_new_map(map, lists[i]);
		i++;
	}
}
