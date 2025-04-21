#include "env_var.h"

void add_var_to_tokens(t_token **tokens, char **args, int i, int j)
{
    int type;
    t_token *token;

    type = get_type_without_set_var(tokens[i]->type);
    token = tokens[i];
    if(tokens[i]->type & e_cmd)
    {
        cs_list_inset_at(g_all.tokens, i, (long)create_token(args[j], e_cmd | e_args));
        token = NULL;
        type -= e_cmd;
        i++;
        j++;
    }
    cs_list_delete(g_all.tokens, i);
    while (args && args[j])
    {
        if(g_all.tokens->count <= i)
            cs_list_add(g_all.tokens, (long)create_token(args[j], type));
        else
            cs_list_inset_at(g_all.tokens, i, (long)create_token(args[j], type));
        token = NULL;
        i++;
        j++;
    }
}

void create_value_token(t_cpp_str *str, t_cpp_str *new_str_token)
{
    t_cs_list *value;
    char *key;
    int first_time;

    first_time = 1;
    value = NULL;
    while(first_time || key[0])
    {
        key = get_key_in_token(str, new_str_token);
        if(key && key[0])
        {
            value = cpp_map_get(g_all.custom_env, key);
            if(value)
                cpp_str_add(new_str_token, value->content);
        }
        else
            return ;
        first_time = 0;
    }
}

void add_var_double_quote_to_tokens(t_cpp_str *value, int i, int type)
{
    t_token *t;
    t_token *new_t;

    new_t = ft_calloc(1, (sizeof(t_token)));
    new_t->s = value->content;
    new_t->type = type;
    t = ((t_token **)(g_all.tokens->content))[i];
    cs_list_delete(g_all.tokens, i);
    if(g_all.tokens->count <= i)
        cs_list_add(g_all.tokens, (long)new_t);
    else
        cs_list_inset_at(g_all.tokens, i, (long)new_t);
}

int get_variable_value(t_token **tokens, int i, int type)
{
    t_cpp_str *new_str_token;
    t_cpp_str *str_token;
    char **args;
    int  j;

    j = 0;
    new_str_token = cpp_str_new();
    str_token = cpp_str_new_substitute(tokens[i]->s);
    create_value_token(str_token, new_str_token);
    if(!(tokens[i]->type & (e_double_quote | e_quote)))
    {
        args = ft_super_split(new_str_token->content, " \t", "");
        if(!args || !args[j])
            return 0;
        add_var_to_tokens(tokens, args, i, j);
    }
    else
        add_var_double_quote_to_tokens(new_str_token, i, type);
    return 1;
}

void get_variables_value()
{
    t_token **tokens;
    int i;
    int res;

    tokens = g_all.tokens->content;
    i = 0;
    while(g_all.tokens->count > i)
    {
        if(tokens[i]->type & e_var_to_get)
            get_variable_value(tokens, i, get_type_without_set_var(tokens[i]->type));
        i++;
    }
}
