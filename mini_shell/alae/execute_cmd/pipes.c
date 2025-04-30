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

void close_cmd_pipe(t_exe_cmd_data *data)
{
    if (data->cmd->input_fd)
        close(data->cmd->input_fd);
    if (data->cmd->output_fd)
        close(data->cmd->output_fd);
    if (data->cmd->pipe)
    {
        if (data->cmd->pipe->next)
        {
            close(data->cmd->pipe->next->fd_write);
            data->cmd->pipe->next->fd_write = -1;
        }
        else
        {
            close(data->cmd->pipe->fd_write);
            data->cmd->pipe->fd_write = -1;
        }
    }
}

void close_fd(t_exe_cmd_data *data)
{
    if (data->cmd)
        close_cmd_pipe(data);
    if (data->old_cmd && data->old_cmd->pipe)
    {
        close(data->old_cmd->pipe->fd_read);
        data->old_cmd->pipe->fd_read = -1;
    }
    data->old_cmd = data->cmd;
}

void dup_fd(t_exe_cmd_data *data)
{
    if (data->cmd->pipe && !data->i)
    {
        close(data->cmd->pipe->fd_read);
        data->cmd->pipe->fd_read = -1;
        dup2(data->cmd->pipe->fd_write, 1);
        close(data->cmd->pipe->fd_write);
        data->cmd->pipe->fd_write = -1;
    }
    else if (data->cmd->pipe && data->i)
    {
        dup2(data->cmd->pipe->fd_read, 0);
        close(data->cmd->pipe->fd_read);
        data->cmd->pipe->fd_read = -1;
        if (data->cmd->pipe->next)
        {
            dup2(data->cmd->pipe->next->fd_write, 1);
            close(data->cmd->pipe->next->fd_write);
            data->cmd->pipe->next->fd_write = -1;
        }
    }
    if (data->cmd->input_fd)
        dup2(data->cmd->input_fd, 0);
    if (data->cmd->output_fd)
        dup2(data->cmd->output_fd, 1);
}