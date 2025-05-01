#include "execute_cmd.h"

void create_pipes(t_exe_cmd_data *data)
{
    if (data->c - 1 <= data->i || data->c == 1)
        return ;
    if (!data->i)
    {
        data->cmds[0]->pipe = create_pipe();
        data->cmds[1]->pipe = data->cmds[0]->pipe;
    }
    else 
    {
        data->cmds[data->i]->pipe->next = create_pipe();
        data->cmds[data->i + 1]->pipe = data->cmds[data->i]->pipe->next;
    }
}

int use_fork(t_exe_cmd_data *data)
{
   if (g_all.cmds->count != 1)
        return 1;
    if (!data->cmd->cmd_path)
        return 0;
    if (!ft_strncmp(data->cmd->cmd_path, "unset", 6))
        return 0;
    if (!ft_strncmp(data->cmd->cmd_path, "cd", 3))
        return 0;
    if (!ft_strncmp(data->cmd->cmd_path, "exit", 5))
        return 0;
    return 1;
}

void run_cmds(t_exe_cmd_data *data)
{
    int p;

    p = 0;
    if(use_fork(data))
        p = fork();
    if(p)
        cs_list_add(data->pid_list, p);
    else
    {
        if (data->cmd->cmd_path)
            dup_fd(data);
        data->builtin = cpp_map_get(g_all.builtins, data->cmd->cmd_path);
        if (data->builtin)
        {
            data->builtin(data->cmd);
            if (use_fork(data))
                ft_exit(0);
        }
        else if (data->cmd->cmd_path)
        {
            execve(data->cmd->cmd_path, data->cmd->args, (char **)(g_all.new_env->content));
            ft_exit(127);
        }
    }
}

void wait_cmds(t_exe_cmd_data *data)
{
    int *pids;
    int i;

    i = 0;
    pids = data->pid_list->content;
    while (i < data->pid_list->count)
    {
        waitpid(pids[i], 0, 0);
        i++;
    }
}

void execute_cmd()
{
    t_exe_cmd_data data;

    if (!g_all.cmds || !g_all.cmds->count)
        return ;
    ft_bzero(&data, sizeof(t_exe_cmd_data));
    data.cmds = g_all.cmds->content;
    data.c = g_all.cmds->count;
    data.cmd = data.cmds[data.i];
    data.pid_list = cs_list_new(sizeof(int));
    
    while (data.c > data.i)
    {
        data.cmd = data.cmds[data.i];
        create_pipes(&data);
        run_cmds(&data);
        data.i++;
    }
    close_fd(&data);
    wait_cmds(&data);
}
