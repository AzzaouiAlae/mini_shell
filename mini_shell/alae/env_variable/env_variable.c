#include "env_var.h"

void init_env_map()
{
    int i;

    i = 0;
    g_all.custom_env = cpp_map_new_capacity(150);
    while(g_all.env[i])
    {
        add_env_var(g_all.env[i], e_global_var);
        i++;
    }
}

int is_var_start(t_cpp_str *str, char ch)
{
    if (!str->content[0])
        return 1;
    if (ch == '\'')
        return 0;
    if(str->content[0] != '$')
        return 0;
    if (str->content[0] == '$' && ft_strchr("\"'", str->content[1]))
        return 0;
    if (str->content[0] == '$' && str->content[1] == '\0')
        return 0;
    return 1;
}

void print_env_var(t_key_value *kvp)
{
    t_cs_list *value;

    value = kvp->value;
    if(value->type)
        printf("%s=%s\n", kvp->key, value->content);
}

void print_env_vars()
{
    cpp_map_foreach(g_all.custom_env, print_env_var);
}
