#include "ft_func.h"

t_cpp_str *ft_itoa(int num)
{
    int i;
    long n;
    t_cpp_str *str;

    i = 0;
    n = num;
    str = cpp_str_new();
    if (n < 0)
    {
        cpp_str_add_char(str, '-');
        n *= -1;
    }
    else if(!n)
        cpp_str_add_char(str, '0');
    while(n > 0)
    {
        if(str->content[0] == '-')
            cpp_str_insert_char(str, n % 10 + '0', 1);
        else
            cpp_str_insert_char(str, n % 10 + '0', 0);
        n /= 10;
    }
    return str;
}

int is_alpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z');
}

int is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}