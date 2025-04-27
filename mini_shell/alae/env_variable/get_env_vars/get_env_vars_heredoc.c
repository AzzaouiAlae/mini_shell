#include "get_env_vars.h"

char *get_env_vars_heredoc(char *input)
{
    t_get_env_data data;

    ft_bzero(&data, sizeof(t_get_env_data));
    data.special_ch = 1;
    data.new_str_token = cpp_str_new();
    data.str_token = cpp_str_new_substitute(input);
    create_value_token(&data);
    return data.new_str_token->content;
}
