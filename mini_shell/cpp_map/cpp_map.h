/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:22:37 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 05:35:53 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_MAP_H
# define CPP_MAP_H
# include "../cs_list/cs_list.h"

typedef struct key_value
{
	char	*key;
	void	*value;
}			t_key_value;

typedef struct s_cpp_map
{
	void	*content;
	int		count;
	int		max_size;
	int		capacity;
}			t_cpp_map;

int			cpp_map_hash_function(char *str);
t_cpp_map	*cpp_map_new(void);
t_cpp_map	*cpp_map_new_capacity(int capacity);
void		cpp_map_add(t_cpp_map *map, char *key, void *value);
void		*cpp_map_get(t_cpp_map *map, char *key);
void		cpp_map_delete(t_cpp_map *map, char *key);
void		cpp_map_clear(t_cpp_map *map);
int			next_prime(int n);
void		cpp_map_resize(t_cpp_map *map, int capacity);
void		cpp_map_foreach(t_cpp_map *map, void (*f)(t_key_value *));

#endif