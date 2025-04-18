#include "cpp_map.h"
#include "../ft_func/ft_func.h"

void *cpp_map_get(t_cpp_map *map, char *key)
{
    int index;
    int i;
    t_cs_list **lists;
    t_key_value **key_values;

    index = cpp_map_hash_function(key) % map->capacity;
    lists = map->content;
    if(!lists[index])
        return NULL;
    i = 0;
    while(lists[index]->count > i)
    {
        key_values = lists[index]->content;
        if(!ft_strcmp(key_values[i]->key, key))
            return key_values[i]->value;
        i++;
    }
    return NULL;
}
