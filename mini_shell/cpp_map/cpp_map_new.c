/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_map_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:22:35 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 10:46:43 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpp_map.h"

t_cpp_map	*cpp_map_new(void)
{
	t_cpp_map	*map;

	map = ft_calloc(1, sizeof(t_cpp_map));
	map->content = ft_calloc(23, sizeof(void *));
	map->capacity = 23;
	map->count = 0;
	map->max_size = (double)map->capacity * .70;
	return (map);
}

t_cpp_map	*cpp_map_new_capacity(int capacity)
{
	t_cpp_map	*map;

	map = ft_calloc(1, sizeof(t_cpp_map));
	map->content = ft_calloc(capacity, sizeof(void *));
	map->capacity = capacity;
	map->count = 0;
	map->max_size = (double)map->capacity * .70;
	return (map);
}
