#include "builtins.h"

int is_builtin(char *cmd)
{
    if (cpp_map_get(g_all.builtins, cmd))
        return 1;
    return 0;
}

void run_builtin_cmds()
{
    int i;
    t_cmd **cmds;
    void (*cmd)(t_cmd *c);

    i = 0;
    cmds = g_all.cmds->content;
    while (i < g_all.cmds->count)
    {
        cmd = cpp_map_get(g_all.builtins, cmds[i]->cmd_path);
        if (cmd)
            cmd(cmds[i]);
        i++;
    }
}
