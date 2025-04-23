#include "env_var.h"

void create_arg_token(t_cpp_str *arg, t_cpp_str *str_token)
{
    char ch;

    ch = '\0';
    while(str_token->content[0])
    {
        if(!ch && ft_strchr("\"'", str_token->content[0]))
            ch = str_token->content[0];
        else if (ch == str_token->content[0])
            ch = '\0';
        if (ch || !ft_strchr(" \t", str_token->content[0]))
        {
            cpp_str_add_char(arg, str_token->content[0]);
            cpp_str_delete_char(str_token, 0);
        }
        else
            return;
    }
}

void pass_space(t_cpp_str *str_token)
{
    while (ft_strchr(" \t", str_token->content[0]))
        cpp_str_delete_char(str_token, 0);
}

char **split_var_token(t_cpp_str *str_token)
{
    char ch;
    t_cs_list *args;
    t_cpp_str *arg;

    ch = '\0';
    args = cs_list_new(sizeof(char *));
    arg = cpp_str_new();
    pass_space(str_token);
    while (str_token->content[0])
    {
        create_arg_token(arg, str_token);
        if(arg->count)
            cs_list_add(args, (long)arg->content);
        else
            return args->content;
        arg = cpp_str_new();
        pass_space(str_token);
    }
    return args->content;
}
