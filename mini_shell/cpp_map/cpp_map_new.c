#include "cpp_map.h"

t_cpp_map *cpp_map_new(int size_of_type)
{
    t_cpp_map *dict;

    dict = ft_calloc(1, sizeof(t_cpp_map));
    dict->content = ft_calloc(23, sizeof(void *));
    dict->capacity = 23;
    dict->count = 0;
    dict->max_size = (double)dict->capacity * .70;
}
