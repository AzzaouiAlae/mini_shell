#include "create_cmd.h"

int check_builtins_cmd(t_create_cmd *data)
{
    void (*cmd)(t_cmd *c);

    cmd = cpp_map_get(g_all.builtins, data->tkn->s);
    if (cmd)
        cmd(data->cmd);
}

void run_builtin_cmds(t_create_cmd *data)
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