#include "execute_cmd.h"

t_pipe *create_pipe()
{
    int p[2];
    t_pipe *_pipe;

    pipe(p);
    _pipe = ft_calloc(1, sizeof(t_pipe));
    _pipe->fd_read = p[0];
    _pipe->fd_write = p[1];
    return (_pipe);
}

void close_fd(t_exe_cmd_data *data)
{
    t_pipe *p;

    p = data->cmds[0]->pipe;
    while (p)
    {
        close(p->fd_read);
        close(p->fd_write);
        p = p->next;
    }
}

void dup_fd(t_exe_cmd_data *data)
{
    if (data->cmd->pipe && !data->i)
        dup2(data->cmd->pipe->fd_write, 1);
    else if (data->cmd->pipe && data->i)
    {
        if (data->cmd->pipe->next)
            dup2(data->cmd->pipe->next->fd_write, 1);
        dup2(data->cmd->pipe->fd_read, 0);
    }
    if (data->cmd->input_fd)
        dup2(data->cmd->input_fd, 0);
    if (data->cmd->output_fd)
        dup2(data->cmd->output_fd, 1);
    close_fd(data);
}
