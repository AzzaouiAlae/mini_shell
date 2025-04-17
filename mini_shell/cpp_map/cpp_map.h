#ifndef CS_cpp_map_H
#define CS_cpp_map_H
#include "../cs_list/cs_list.h"

typedef struct key_value
{
    char	*key;
    void	*value;
}				t_key_value;

typedef struct s_cpp_map
{
    void         *content;
    int         size_of_type;
    int         count;
    int         max_size;
    int         capacity;
}				t_cpp_map;

int cpp_map_hash_function(char *str);
t_cpp_map *cpp_map_new(int size_of_type);
void cpp_map_add(t_cpp_map *map, char *key, void *value);
void *cpp_map_get(t_cpp_map *map, char *key);
void cpp_map_delete(t_cpp_map *map, char *key);
void cpp_map_clear(t_cpp_map *map);
int next_prime(int n);


#endif