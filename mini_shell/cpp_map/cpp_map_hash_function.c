#include "cpp_map.h"

int cpp_map_hash_function(char *str)
{
    long num;

    num = 0;
    while(str && *str)
        num *= *str++;
    return (int)(num);
}
