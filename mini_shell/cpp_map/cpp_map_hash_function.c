#include "cpp_map.h"

int cpp_map_hash_function(char *str)
{
    long num;

    num = 1;
    while(str && *str)
        num += *str++;
    str--;
    num = num * *str;
    return (int)(num);
}
