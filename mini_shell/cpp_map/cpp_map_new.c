#include "cpp_map.h"

t_cpp_map *cpp_map_new()
{
    t_cpp_map *map;

    map = ft_calloc(1, sizeof(t_cpp_map));
    map->content = ft_calloc(23, sizeof(void *));
    map->capacity = 23;
    map->count = 0;
    map->max_size = (double)map->capacity * .70;
}

t_cpp_map *cpp_map_new_capacity(int capacity)
{
    t_cpp_map *map;

    map = ft_calloc(1, sizeof(t_cpp_map));
    map->content = ft_calloc(capacity, sizeof(void *));
    map->capacity = capacity;
    map->count = 0;
    map->max_size = (double)map->capacity * .70;
}
