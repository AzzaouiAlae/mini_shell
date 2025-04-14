#include "mini_shell.h"

t_global g_all;

void init_g_all()
{
    ft_bzero(&g_all, sizeof(t_global));
}

// int main(int argc, char *argv[], char *env[])
// {
//     printf("hello\n");
// }