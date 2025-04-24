#include "debug.h"

void print_func_data(char *str, void (*func)(void))
{
    int count = (32 - ft_strlen(str)) / 2;
    int i = 0;
    printf("\n------------------------------\n");
    while(count - 1 > i++)
        printf(" ");
    printf("%s\n", str);
    printf("------------------------------\n");
    if(!func)
        return;
    func();
    print_tokens();
    printf("=================================\n");
}

void print_cmds()
{
    char *str = "create_cmd";
    int i = 0;
    int count = (34 - ft_strlen(str)) / 2;
    printf("\n=================================\n");
    while(count - 1 > i++)
        printf(" ");
    printf("%s\n", str);
    printf("=================================\n");
    create_cmd();
    i = 0;
    t_cmd **cmds = g_all.cmds->content;
    while(i < g_all.cmds->count)
    {
        printf("command %d\n", i + 1);
        print_cmd(cmds[i]);
        printf("\n------------------------------\n");
        i++;
    }
    printf("=================================\n");
}

void print_cmd(t_cmd *cmd)
{
    printf("cmd_path = %s\n", cmd->cmd_path);
    printf("args = ");
    for(int i = 0; cmd->args[i]; i++)
    {
        if(cmd->args[i + 1])
            printf("[%s]\t", cmd->args[i]);
        else 
            printf("[%s]", cmd->args[i]);
    }
    printf("\nheredoc_fd = %d\t", cmd->heredoc_fd);
    printf("redir_in_fd = %d\t", cmd->redir_in_fd);
    printf("redir_out_app_fd = %d\t", cmd->redir_out_app_fd);
    printf("redir_out_trun_fd = %d\t", cmd->redir_out_trun_fd);
}

void process_cmd(char *s)
{
    print_func_data("split_tokens", NULL);
    split_tokens(s, " |<>\t$", "\"'");
    print_tokens();
    printf("=================================\n");
    if(!g_all.tokens->count)
    {
        set_exit_status();
        return ;
    }
    ft_check_syntax_error();
    if(g_all.cmd_error_status)
    {
        set_exit_status();
        return;
    }
    print_func_data("get_variables_value", get_variables_value);
    if(!g_all.tokens->count)
    {
        set_exit_status();
        return ;
    }
    print_func_data("add_vars_to_env", add_vars_to_env);
    if(!g_all.tokens->count)
    {
        set_exit_status();
        return ;
    }
    print_func_data("rm_single_double_qoute", rm_single_double_qoute);
    if(!g_all.tokens->count)
    {
        set_exit_status();
        return ;
    }
    print_func_data("open_redirection_files", open_redirection_files);
    if(!g_all.tokens->count)
    {
        set_exit_status();
        return ;
    }
    print_cmds();
    set_exit_status();
}

char *get_enum_str(int type)
{
    t_cpp_str *str = cpp_str_new();
    int i = 0;

    char *strs[] = {"e_none", "e_args", "e_pipe", "e_heredoc",
 		"e_redir_out_app", "e_redir_out_trun", "e_redir_in", "e_var_to_get",
 		"e_quote", "e_double_quote", "e_file_name", "e_cmd", "e_path", 
        "e_set_var", "e_var_to_set" ,"e_delimiter", "e_heredoc_fd", 
        "e_redir_out_app_fd", "e_redir_out_trun_fd", "e_redir_in_fd", 0};
    for(int i = 1, j = 1; strs[j]; i *= 2, j++)
    {
        if((type & i) == i)
        {
            cpp_str_add(str, strs[j]);
            cpp_str_add_char(str, ' ');
        }
    }
    return str->content;
}

void print_tokens()
{
    int i;
    t_token **t;
    int fd_type;
    
    i = 0;
    t = g_all.tokens->content;
    fd_type = (e_heredoc_fd | e_redir_in_fd | e_redir_out_trun_fd | e_redir_out_app_fd);
    while(i < g_all.tokens->count)
    {   
        if((t[i]->type & fd_type))
            printf("[%d] = %s\n", *((int *)t[i]->s), get_enum_str(t[i]->type));
        else
            printf("[%s] = %s\n", t[i]->s, get_enum_str(t[i]->type));
        i++;
    }
}