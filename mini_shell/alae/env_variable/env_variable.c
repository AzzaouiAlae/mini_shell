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

void print_env_cmd(t_key_value *kvp)
{
    t_cmd *cmd;
    t_cs_list *value;
    
    value = kvp->value;
    cmd = g_all.current_cmd;
    if(value->type)
        printf("%s=%s\n", kvp->key, value->content);
}

void print_export_vars_cmd(t_cmd *cmd)
{
    int fd;
    int old_fd;

    fd = 1;
    if(cmd && cmd->redir_out_app_fd)
        fd = cmd->redir_out_app_fd;
    if(cmd && cmd->redir_out_trun_fd)
        fd = cmd->redir_out_trun_fd;
    if(cmd && cmd->pipe)
        fd = cmd->pipe->fd_write;
    g_all.current_cmd = cmd;
    old_fd = dup(1);
    dup2(fd, 1);
    cpp_map_foreach(g_all.custom_env, print_env_cmd);
    dup2(old_fd, 1);
}
