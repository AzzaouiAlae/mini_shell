#include "execute_cmd.h"

void execute_cmd()
{
    t_exe_cmd_data data;
    
    ft_bzero(&data, sizeof(t_exe_cmd_data));
    data.cmds = g_all.cmds->content;
    data.c = g_all.cmds->count;
    while (data.c > data.i)
    {
        data.cmd = data.cmds[data.i];
        data.builtin = cpp_map_get(g_all.builtins, data.cmd->cmd_path);
        if (data.builtin)
            data.builtin(data.cmd);
        data.i++;
    }
}
