#include "get_env_vars.h"

void add_var_cmd(t_get_env_data *data)
{
    t_token *token;
    int type;

    type = e_cmd | e_args;
    if((data->tokens[data->i]->type & e_cmd) || is_cmd_type())
    {
        token = create_token(data->args[data->j], e_cmd | e_args);
        cs_list_inset_at(g_all.tokens, data->i, (long)token);
        data->i++;
        data->j++;
    }
}

void add_var_args(t_get_env_data *data)
{
    t_token *token;

    token = create_token(data->args[data->j], data->type);
    if(g_all.tokens->count <= data->i)
        cs_list_add(g_all.tokens, (long)token);
    else
        cs_list_inset_at(g_all.tokens, data->i, (long)token);
    token = NULL;
    data->i++;
    data->j++;
}

void add_var_to_tokens(t_get_env_data *data)
{
    t_token *token;

    data->j = 0;
    data->type = del_set_var(data->type);
    token = data->tokens[data->i];
    add_var_cmd(data);
    cs_list_delete(g_all.tokens, data->i);
    while (data->args && data->args[data->j])
        add_var_args(data);
}
