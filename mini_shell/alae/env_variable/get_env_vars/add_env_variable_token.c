#include "get_env_vars.h"

void add_var_cmd(t_get_env_data *data)
{
    t_token *token;

    if((data->tokens[data->i]->type & e_cmd) || is_cmd_type())
    {
        token = create_token(data->args[data->j], data->type);
        cs_list_inset_at(g_all.tokens, data->i, (long)token);
        data->i++;
        data->j++;
    }
}

void add_var_args(t_get_env_data *data)
{
    t_token *token;

    if (data->type & e_cmd)
        data->type -= e_cmd;
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
    data->j = 0;
    data->type = del_set_var(data->tokens[data->i]->type) | is_cmd_type();
    if (data->type & e_double_quote)
        data->type -= e_double_quote;
    if (data->type & e_quote)
        data->type -= e_quote;
    add_var_cmd(data);
    cs_list_delete(g_all.tokens, data->i);
    while (data->args && data->args[data->j])
        add_var_args(data);
    data->i--;
}
