#include "cpp_map.h"

t_dictionary *dictionary_new(int size_of_type)
{
    t_dictionary *dict;

    dict = ft_calloc(1, sizeof(t_dictionary));
    dict->content = ft_calloc(1, sizeof(void *) * 23);
    dict->capacity = 23;
    dict->count = 0;
    dict->max_size = (double)dict->capacity * .70;
}
