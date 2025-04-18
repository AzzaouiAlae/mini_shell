#include "env_var.h"

void add_env_var(char *kvp)
{
    t_cs_list *key_list;
    t_cs_list *value_list;
    int value_len;
    int key_len;

    key_len = ft_strchr(kvp, '=') - kvp;
    key_list = cs_list_new_capacity(1, key_len);
    value_len = ft_strlen(ft_strchr(kvp, '=') + 1);
    value_list = cs_list_new_capacity(1, value_len);
    cs_list_add_range(key_list, key_len, kvp);
    cs_list_add_range(value_list, value_len, ft_strchr(kvp, '=') + 1);
    cpp_map_add(g_all.custom_env, key_list->content, value_list);
}

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
