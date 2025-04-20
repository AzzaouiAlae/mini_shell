#include "env_var.h"

void init_env_map()
{
    int i;

    i = 0;
    g_all.custom_env = cpp_map_new_capacity(150);
    while(g_all.env[i])
    {
        add_env_var(g_all.env[i]);
        i++;
    }
}
