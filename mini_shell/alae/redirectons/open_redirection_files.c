#include "../../mini_shell.h"

int get_open_permission(int type)
{
    if (type & e_redir_in)
        return O_RDONLY;
    if (type & e_redir_out_app)
        return O_APPEND | O_CREAT | O_WRONLY;
    if (type & e_redir_out_trun)
        return O_TRUNC | O_CREAT | O_WRONLY;
    return 0;
}

int get_type(int type)
{
    if (type & e_redir_in)
        return e_redir_in_fd;
    if (type & e_redir_out_app)
        return e_redir_out_app_fd;
    if (type & e_redir_out_trun)
        return e_redir_out_trun_fd;
    return 0;
}

void print_error(char *file_name)
{
    t_cpp_str *str;

    str = cpp_str_new();
    cpp_str_add(str, "mini-shell: ");
    cpp_str_add(str, file_name);
    cpp_str_add(str, ": No such file or directory\n");
    write(2, str->content, str->count);
    g_all.cmd_error_status = 1;
}

void open_redirection_file(t_token **tokens, int i)
{
    int fd;
    int open_perm;
    t_token *token;

    if(!tokens[i + 1])
    {
        cs_list_delete(g_all.tokens, i);
        return ;
    }
    open_perm = get_open_permission(tokens[i]->type);
    fd = open(tokens[i + 1]->s, open_perm, 0666);
    if(fd == -1)
        print_error(tokens[i + 1]->s);
    if (tokens[i]->type & (e_redir_out_app | e_redir_out_trun))
        dup2(fd, 1);
    token = ft_calloc(1, sizeof(t_token));
    token->s = ft_calloc(1, sizeof(int));
    *((int *)(token->s)) = fd;
    token->type = get_type(tokens[i]->type);
    cs_list_delete(g_all.tokens, i);
    cs_list_delete(g_all.tokens, i);
    cs_list_inset_at(g_all.tokens, i, (long)token);
}

void open_redirection_files()
{
    t_token **tokens;
    int i;
    int res;
    int old_fd;

    i = 0;
    old_fd = dup(1);
    tokens = g_all.tokens->content;
    while(g_all.tokens->count > i)
    {
        if(tokens[i]->type & (e_redir_in | e_redir_out_app | e_redir_out_trun))
            open_redirection_file(tokens, i);
        if (tokens[i]->type & e_pipe)
            dup2(old_fd, 1);
        i++;
    }
    dup2(old_fd, 1);
    close(old_fd);
}
