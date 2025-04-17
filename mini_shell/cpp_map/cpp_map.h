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
    void         *content;
    int         size_of_type;
    int         count;
    int         max_size;
    int         capacity;
}				t_dictionary;

int dictionary_hash_function(char *str);
t_dictionary *dictionary_new(int size_of_type);
void dictionary_add(t_dictionary *dict, char *key, void *value);
void *dictionary_get(t_dictionary *dict, char *key);
void dictionary_delete(t_dictionary *dict, char *key);
void dictionary_clear(t_dictionary *dict);
int next_prime(int n);


#endif