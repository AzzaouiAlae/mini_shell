#include "cpp_map.h"

void		cpp_map_clear(t_cpp_map *map)
{
    int index;
    int i;
    t_cs_list **lists;
    t_key_value **key_values;

    index = -1;
    lists = map->content;
    while(++index < map->capacity)
    {
        if(!lists[index])
            continue;
        i = 0;
        while(lists[index]->count > i)
        {
            key_values = lists[index]->content;
            cs_list_delete(lists[index], i);
            i++;
        }
    }
}
