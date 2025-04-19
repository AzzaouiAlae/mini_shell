#include "env_var.h"

void add_env_var(char *kvp)
{
    t_cs_list *key_list;
    t_cs_list *value_list;
    int value_len;
    int key_len;
    char *s;

    s = ft_strchr(kvp, '=');
    if(!s)
        return ;
    key_len = s - kvp;
    if(*(s - 1) == '+')
        key_len--;
    key_list = cs_list_new_capacity(1, key_len);
    cs_list_add_range(key_list, key_len, kvp);
    if(*(s - 1) == '+')
        value_list = cpp_map_get(g_all.custom_env, key_list->content);
    else
    {
        value_len = ft_strlen(s + 1);
        value_list = cs_list_new_capacity(1, value_len);
    }
    cs_list_add_range(value_list, value_len, s + 1);
    cpp_map_add(g_all.custom_env, key_list->content, value_list);
}

void init_env_map()
{
    int i;

    i = 0;
    g_all.custom_env = cpp_map_new_capacity(150);
    while(g_all.env[i])
    {
        add_env_var(g_all.env[i]);
        i++;
    }
}

char *get_key_in_token(t_token *token)
{
    char *s;
    int len;

    s = ft_strchr(token, '$');
    if(!s)
        return NULL;
    len = 0;
    while(ft_strchr(token, s[len]))
        len++;
    

}

t_token *create_token(char s, int type)
{
    t_token *t;

    t = ft_calloc(1, sizeof(t_token));
    t->s = s;
    t->type = type;
    return t;
}

void add_args_to_tokens(t_token **tokens, char **args, int i, int j)
{
    int type;

    type = tokens[i]->type - e_var_to_get;
    if(tokens[i]->type & e_cmd)
    {
        cs_list_inset_at(g_all.tokens, i, create_token(args[j], e_cmd | e_args));
        type -= e_cmd;
        i++;
        j++;
    }
    cs_list_delete(g_all.tokens, i + j);
    while (args[j])
    {
        cs_list_inset_at(g_all.tokens, i, create_token(args[j], type));
        i++;
        j++;
    }
}

int replace_var(t_token **tokens, int i)
{
    char *key;
    char *value;
    char **args;
    int type;
    int j;

    j = 0;
    key = get_key_in_token(tokens[i]);
    if(!key)
        return 0;
    value = cpp_map_get(g_all.custom_env, key);
    type = tokens[i]->type - e_set_var;
    if(tokens[i]->type & e_double_quote == 0)
    {
        args = ft_super_split(value, " \t", "");
        if(!args && !args[j])
            return 0;
        add_args_to_tokens(tokens, args, i, j);
    }
    else
    {
        cs_list_delete(g_all.tokens, i);
        cs_list_inset_at(g_all.tokens, i, create_token(args[j], type));
    }
    return 1;
}

void replace_vars()
{
    t_token **tokens;
    int i;
    char *s;

    tokens = g_all.tokens->content;
    i = 0;
    while(g_all.tokens->count > i)
    {
        if(tokens[i]->type & e_var_to_get)
        {
            if(!replace_var(tokens, i))
                cs_list_delete(g_all.tokens, i--);
        }
        i++;
    }
}
