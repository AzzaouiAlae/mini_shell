#include "get_env_vars.h"

char *get_env_vars_heredoc(char *input)
{
    t_get_env_data data;

    ft_bzero(&data, sizeof(t_get_env_data));
    data.new_str_token = cpp_str_new();
    data.str_token = cpp_str_new_substitute(input);
    cpp_str_insert_char(data.str_token, '"', 0);
    cpp_str_add_char(data.str_token, '"');
    create_value_token(&data);
    
    return data.new_str_token->content;
}