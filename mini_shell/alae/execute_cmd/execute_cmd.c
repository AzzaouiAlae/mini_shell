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
    if (data->cmd->input_fd == -1 || data->cmd->output_fd == -1)
        return 0;
    if (!ft_strncmp(data->cmd->cmd_path, "export", 7) && 
        ft_strslen(data->cmd->args) > 1)
        return 0;
    if (!ft_strncmp(data->cmd->cmd_path, "unset", 6))
        return 0;
    if (!ft_strncmp(data->cmd->cmd_path, "cd", 3))
        return 0;
    if (!ft_strncmp(data->cmd->cmd_path, "exit", 5))
        return 0;
    return 1;
}

void run(t_exe_cmd_data *data)
{
    if (data->cmd->cmd_path)
        dup_fd(data);
    data->builtin = cpp_map_get(g_all.builtins, data->cmd->cmd_path);
    if (data->builtin)
    {
        data->builtin(data->cmd);
        if (use_fork(data))
            ft_exit(g_all.cmd_error_status);
    }
    else if (data->cmd->cmd_path)
    {
        if (data->cmd->input_fd != -1 && data->cmd->output_fd != -1)
        {
            execve(data->cmd->cmd_path, data->cmd->args, 
                (char **)(g_all.new_env->content));
            ft_exit(errno);
        }
        ft_exit(g_all.cmd_error_status);
    }
    if (use_fork(data))
            ft_exit(g_all.cmd_error_status);
}

void run_cmds(t_exe_cmd_data *data)
{
    int p;
    // t_cpp_str *s_err;

    p = 0;
    // if (data->cmd->pipe && data->cmd->pipe->bad_fd)
    // {
    //     s_err = cpp_str_new();
    //     cpp_str_add(s_err, data->cmd->args[0]);
    //     cpp_str_add(s_err, ": write error: Bad file descriptor\n");
    //     write(2, s_err->content, s_err->count);
    //     return ;
    // }
    if(use_fork(data))
        p = fork();
    if(p)
        cs_list_add(data->pid_list, p);
    else
        run(data);
}

void wait_cmds(t_exe_cmd_data *data)
{
    int i;
    int status;
    int *pids;

    i = 0;
    pids = data->pid_list->content;
    while (i < data->pid_list->count)
    {
        waitpid(pids[i], &status, 0);
        i++;
    }
    if (data->pid_list->count)
        g_all.cmd_error_status = 0;
    if (WIFEXITED(status))
        g_all.cmd_error_status = WEXITSTATUS(status);
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
