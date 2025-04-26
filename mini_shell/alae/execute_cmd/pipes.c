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

// void add_pipe(t_pipe *p)
// {
//     t_pipe *pipe1;

//     if (!g_all.pipes)
//         g_all.pipes = p;
//     while (pipe1->next)
// }
