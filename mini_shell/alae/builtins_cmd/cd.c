#include "builtins.h"

void add_to_env(t_cpp_str *s, char *str_to_change, char *var)
{
    t_cs_list *str;

    str = cs_list_new(1);
    if (s)
    {
        cs_list_add_range(str, s->count, s->content);
        str->type = e_global_var;
        cpp_map_add(g_all.custom_env, var, (void *)str);
    }
    else if (str_to_change)
    {
        cs_list_add_range(str, ft_strlen(str_to_change), str_to_change);
        str->type = e_global_var;
        cpp_map_add(g_all.custom_env, var, (void *)str);
    }
}

t_cpp_str *get_from_env(char *var)
{
    t_cpp_str *str;
    t_cs_list *value;

    str = cpp_str_new();
    value = cpp_map_get(g_all.custom_env, var);
    if (!value)
    {
        if (!ft_strncmp("HOME", var, 5))
            get_stell_home(e_missing_home);
        if (!ft_strncmp("OLDPWD", var, 7))
            write(2, "Minishell: cd: OLDPWD not set\n", 30);
        return str;
    }
    cpp_str_add(str, value->content);
    return str;
}

void invalid_cwd(char **cwd, char *arg, char *buf)
{
    *cwd = getcwd(buf, 4097);
    if (!(*cwd))
    {
        *cwd = my_ft_strjoin(get_from_env("PWD")->content, "/");
        *cwd = my_ft_strjoin(*cwd, arg);
        write(2, "error retrieving current directory: ", 36);
        write(2, "getcwd: cannot access parent directories: ",42);
        write(2, "No such file or directory\n", 26);
    }
    add_to_env(get_from_env("PWD"), NULL, "OLDPWD");
    add_to_env(NULL, *cwd, "PWD");
}

void cd_dash(t_cmd *cmd, char *buf)
{
    char *cwd;

    if (cmd->args[1][0] == '-' && cmd->args[1][1] == '\0')
    {
        if (chdir(get_from_env("OLDPWD")->content) == -1)
            return;
        cwd = getcwd(buf, 4097);
        add_to_env(get_from_env("PWD"), NULL, "OLDPWD");
        add_to_env(NULL, cwd, "PWD");
    }
    else if (!ft_strncmp("--", cmd->args[1], 3))
    {
        ft_free(cmd->args[1]);
        cmd->args[1] = NULL;
        cd(cmd);
    }
}

void cd(t_cmd *cmd)
{
    char *cwd, *(buf);
    buf = ft_calloc (1, 4097);
    get_stell_home(e_exist_home);
    if (count_args(cmd->args) > 2)
    {
        g_all.cmd_error_status = 1;
        write (2, "Minishell : cd: too many arguments\n", 35);
        return;
    }
    else if (count_args(cmd->args) == 1 || (cmd->args[1] && cmd->args[1][0] == '~'))
    {
        if (chdir(get_from_env("HOME")->content) == -1 \
            && print_cd_error(get_from_env("HOME")->content))
            return;
        add_to_env(get_from_env("PWD"), NULL, "OLDPWD");
        add_to_env(NULL, getcwd(buf, 4097), "PWD");
    }
    else if (cmd->args[1] && (!ft_strncmp("--", cmd->args[1], 3) || !ft_strncmp("-", cmd->args[1], 2)))
        cd_dash(cmd, buf);
    else
    {
        if (chdir(cmd->args[1]) == -1 && print_cd_error(cmd->args[1]))
            return;
        invalid_cwd(&cwd, cmd->args[1], buf);
    }
}
