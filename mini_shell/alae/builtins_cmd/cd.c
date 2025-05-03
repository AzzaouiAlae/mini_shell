#include "builtins.h"

int get_stell_home (int set)
{
    static int home;

    if (set == 100)
        home = 1;
    else if (set == 200)
        home = 0;
    return (home);
    
}
int print_cd_error(char *arg)
{
    if (get_stell_home(0) == 1)
    {
        g_all.cmd_error_status = 1;
        perror(my_ft_strjoin("Minishell cd: ", arg));
    }
    else
        write(2, "Minishell: cd: HOME not set\n", 28);
    return 1;
}

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

t_cpp_str *get_from_env(char *var, t_cmd *cmd)
{
    t_cpp_str *str;
    t_cs_list *value;


    str = cpp_str_new();
    value = cpp_map_get(g_all.custom_env, var);
    if (!value)
    {
        if (ft_strncmp("HOME", var, ft_strlen(var)))
            get_stell_home(200);
        return str;
    }
    cpp_str_add(str, value->content);
    if (cmd && cmd->args[1])
        cpp_str_add(str, &(cmd->args[1][1]));
    return str;
}

// void invalid_cwd(char *cwd, char *arg, char *buf)
// {
    
// }
// tmjnina hadi
void cd(t_cmd *cmd)
{
    char *cwd, (buf[4097]);

    // ft_calloc (1, 4097);
    ft_bzero(buf, 4097);
    get_stell_home(100);
    if (count_args(cmd->args) > 2)
    {
        g_all.cmd_error_status = 1;
        write (2, "Minishell : cd: too many arguments\n", 35);
        return;
    }
    else if (count_args(cmd->args) == 1 || (cmd->args[1] && cmd->args[1][0] == '~'))
    {
        if (chdir(get_from_env("HOME", cmd)->content) == -1 \
            && print_cd_error(get_from_env("HOME", cmd)->content))
            return;
        add_to_env(get_from_env("PWD", NULL), NULL, "OLDPWD");
        add_to_env(NULL, getcwd(buf, 4097), "PWD");
    }
    else
    {
        if (chdir(cmd->args[1]) == -1 && print_cd_error(cmd->args[1]))
            return;
        cwd = getcwd(buf, 4097);
        if (!cwd)
        {
            cwd = my_ft_strjoin(get_from_env("PWD", NULL)->content, "/");
            cwd = my_ft_strjoin(cwd, cmd->args[1]);
            write(2, "error retrieving current directory: ", 36);
            write(2, "getcwd: cannot access parent directories: ",42);
            write(2, "No such file or directory\n", 26);
        }
        add_to_env(get_from_env("PWD", NULL), NULL, "OLDPWD");
        add_to_env(NULL, cwd, "PWD");
    }
}
