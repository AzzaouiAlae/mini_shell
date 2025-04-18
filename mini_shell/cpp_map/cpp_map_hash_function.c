#include "cpp_map.h"

int cpp_map_hash_function(char *str)
{
    long num;
    int i;

    num = 1;
    i = 0;
    while(str && str[i])
        num += str[i++];
    if(i)
    {
        num *= str[i - 1];
        num *= str[(i - 1) / 2];
        num *= str[0];
    }
    return (int)(num);
}
