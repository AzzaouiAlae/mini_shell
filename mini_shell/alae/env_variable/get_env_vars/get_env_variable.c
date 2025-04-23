#include "get_env_vars.h"

void create_value_token(t_get_env_data *data)
{
    t_cs_list *value;
    char *key;
    int first_time;

    first_time = 1;
    value = NULL;
    while(first_time || key[0])
    {
        key = create_key_token(data->str_token, data->new_str_token);
        if(key && key[0])
        {
            value = cpp_map_get(g_all.custom_env, key);
            if(value)
                cpp_str_add(data->new_str_token, value->content);
        }
        else
            return ;
        first_time = 0;
    }
}

int get_variable_value(t_get_env_data *data)
{
    data->new_str_token = cpp_str_new();
    data->str_token = cpp_str_new_substitute(data->tokens[data->i]->s);
    create_value_token(data);
    data->args = split_var_token(data->new_str_token);
    if(!data->args || !data->args[0])
    {
        cs_list_delete(g_all.tokens, data->i);
        return 0;
    }
    add_var_to_tokens(data);
    return 1;
}

void get_variables_value()
{
    t_get_env_data data;

    ft_bzero(&data, sizeof(t_get_env_data));
    data.tokens = g_all.tokens->content;
    while(g_all.tokens->count > data.i)
    {
        if(data.tokens[data.i]->type & e_var_to_get)
        {
            data.type = data.tokens[data.i]->type;
            get_variable_value(&data);
        }
        data.i++;
    }
}
