#include "cpp_map.h"
#include "../ft_func/ft_func.h"

int add_item_to_list(t_key_value **key_values, int count, t_key_value *key_value)
{
    int i;

    i = 0;
    while(count > i)
    {
        if(!ft_strcmp(key_values[i]->key, key_value->key))
        {
            key_values[i]->value = key_value->value;
            return 0;
        }
    }
    return 1;
}

void add_item(t_cpp_map *map, t_cs_list **list, t_key_value *key_val, int i)
{
    t_key_value **key_values;

    if(list[i])
    {
        key_values = list[i]->content;
        if(add_item_to_list(key_values, list[i]->count, key_val))
        {
            cs_list_add(list[i], (long)key_val);
            map->count++;
        }
    }
    else
    {
        list[i] = cs_list_new(sizeof(t_key_value *));
        cs_list_add(list[i], (long)key_val);
        map->count++;
    }
}

void cpp_map_add(t_cpp_map *map, char *key, void *value)
{
    int index;
    int i;
    t_key_value *key_value;
    t_cs_list **list;

    i = 0;
    list = map->content;
    key_value = ft_calloc(1, sizeof(t_key_value));
    key_value->key = key;
    key_value->value = value;
    index = cpp_map_hash_function(key) % map->capacity;
    add_item(map, list, key_value, index);
}
