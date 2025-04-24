#include "env_var.h"

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
