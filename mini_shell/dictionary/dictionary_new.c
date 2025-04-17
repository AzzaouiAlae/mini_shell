#include "dictionary.h"

t_dictionary *dictionary_new(int size_of_type)
{
    t_dictionary *dict;

    dict = ft_calloc(1, sizeof(t_dictionary));
    dict->list = cs_list_new_capacity(sizeof(t_cs_list *), 23);
    
}
