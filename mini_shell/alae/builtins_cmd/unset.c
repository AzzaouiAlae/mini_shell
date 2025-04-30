#include "builtins.h"

void unset(t_cmd *cmd)
{
    //printf("this command is not implemented yet\n");
    int i;

    i = 1;
    while (cmd->args && cmd->args[i])
    {
        cpp_map_delete(g_all.custom_env, cmd->args[i]);
        i++;
    }
}
