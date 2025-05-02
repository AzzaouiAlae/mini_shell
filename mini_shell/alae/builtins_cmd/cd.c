#include "builtins.h"

int count_args(char **args)
{
    int i;

    i = 0;
    if (!args)
        return(0);
    while(args[i])
        i++;
    return(i);
}

void cd(t_cmd *cmd)
{
    if (count_args(cmd->args) > 2)
    {
        g_all.cmd_error_status = 1;
        write (2, "Minishell : cd: too many arguments\n", 35);
        return;
    }
    else if (count_args(cmd->args) == 1)
    {
        chdir((char *)(((t_cs_list *)cpp_map_get(g_all.custom_env, "HOME"))->content));
    }
    else
    {
        if (chdir(cmd->args[1]) == -1)
        {
            g_all.cmd_error_status = 1;
            perror(my_ft_strjoin("Minishell cd: ", cmd->args[1]));
            return;
        }
    }
}