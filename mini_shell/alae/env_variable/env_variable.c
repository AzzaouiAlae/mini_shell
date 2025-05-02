#include "env_var.h"

void create_kvp()
{
    t_key_value *kvp;
    
}

void init_env_map()
{
    int i;
    t_cpp_str *str;

    i = 0;
    g_all.custom_env = cpp_map_new_capacity(150);
    while(g_all.env[i])
    {
        add_env_var(g_all.env[i], e_global_var);
        i++;
    }
    i = 0;
    while(g_all.argv[i])
    {
        str = ft_itoa(i);
        cpp_str_add(str, "=");
        cpp_str_add(str, g_all.argv[i]);
        add_env_var(str->content, e_local_var);
        i++;
    }
    set_exit_status();
}
