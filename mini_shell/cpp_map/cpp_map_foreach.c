#include "cpp_map.h"

void exec_func(t_key_value **kvps, int count, void (*f)(t_key_value *))
{
    int j;

    j = 0;
    while(j < count)
    {
        f(kvps[j]);
        j++;
    }
}

void cpp_map_foreach(t_cpp_map *map, void (*f)(t_key_value *))
{
    int i;
    t_key_value **kvps;
    t_cs_list **lists;

    if(!map || !f)
        return ;
    i = 0;
    lists = map->content;
    while(i < map->capacity)
    {
        if(lists[i])
            exec_func(lists[i]->content, lists[i]->count, f);
        i++;
    }
}
