#ifndef CS_DICTIONARY_H
#define CS_DICTIONARY_H
#include "../cs_list/cs_list.h"

typedef struct key_value
{
    char	*key;
    void	*value;
}				key_value;

typedef struct s_dictionary
{
    t_cs_list	*list;
}				t_dictionary;

int dictionary_hash_function(char *str);
t_dictionary *dictionary_new(int size_of_type);
void dictionary_add(t_dictionary *dict, char *key, void *value);
void *dictionary_get(t_dictionary *dict, char *key);
void dictionary_delete(t_dictionary *dict, char *key);
void dictionary_clear(t_dictionary *dict);



#endif