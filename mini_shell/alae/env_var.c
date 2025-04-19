#include "env_var.h"

t_cs_list *create_value_list(char *s, int *value_len, t_cs_list *k)
{
    t_cs_list *str;
    char ch;
    int i;

    i = 1;
    str = cs_list_new_capacity(1, ft_strlen(s));
    ch = '\0';
    while(s[i])
    {
        if(ch == '\0' && (s[i] == '\"' || s[i] == '\''))
            ch = s[i];
        else if(s[i] == '\"' || s[i] == '\'')
            ch ='\0';
        else
            cs_list_add(str, s[i]);
        i++;
    }
    return str;
}

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
    value_list = create_value_list(s, &value_len, key_list);
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

    s = ft_strchr(token->s, '$');
    if(!s)
        return NULL;
    s++;
    len = 0;
    while(s[len] && !ft_strchr(" |<>\t$\"'", s[len]))
        len++;
    return ft_strldup(s, len);
}

t_token *create_token(char *s, int type, t_token *token)
{
    t_token *t;
    t_cs_list *str;
    int len1;
    int len2;

    len1 = 0;
    t = ft_calloc(1, (sizeof(t_token)));
    if(token)
        len1 = ft_strchrlen(token->s, '$');
    len2 = ft_strlen(s);
    str = cs_list_new_capacity(sizeof(char), len1 + len2 + 1);
    if(token)
        cs_list_add_range(str, len1, token->s);
    cs_list_add_range(str, ft_strlen(s), s);
    len1++;
    while(token && token->s[len1] && !ft_strchr(" |<>\t$\"'", token->s[len1]))
        len1++;
    if(token && token->s[len1])
        cs_list_add_range(str, ft_strlen(&(token->s[len1])), &(token->s[len1]));
    t->s = str->content;
    t->type = type;
}

int get_type_without_set_var(int type)
{
    if(type & e_var_to_get)
        return type - e_var_to_get;
    return type;
}

void add_var_to_tokens(t_token **tokens, char **args, int i, int j)
{
    int type;
    t_token *token;

    type = get_type_without_set_var(tokens[i]->type);
    token = tokens[i];
    if(tokens[i]->type & e_cmd)
    {
        cs_list_inset_at(g_all.tokens, i, (long)create_token(args[j], e_cmd | e_args, token));
        token = NULL;
        type -= e_cmd;
        i++;
        j++;
    }
    cs_list_delete(g_all.tokens, i);
    while (args[j])
    {
        if(g_all.tokens->count <= i)
            cs_list_add(g_all.tokens, (long)create_token(args[j], e_args, token));
        else
            cs_list_inset_at(g_all.tokens, i, (long)create_token(args[j], e_args, token));
        token = NULL;
        i++;
        j++;
    }
}

void add_var_double_quote_to_tokens(t_cs_list *value, int i, int type)
{
    t_token *t;

    t = ((t_token **)(g_all.tokens->content))[i];
    cs_list_delete(g_all.tokens, i);
    if(g_all.tokens->count <= i)
        cs_list_add(g_all.tokens, (long)create_token(value->content, type, t));
    else
        cs_list_inset_at(g_all.tokens, i, (long)create_token(value->content, type, t));
}

int replace_var(t_token **tokens, int i, int type)
{
    char *key;
    t_cs_list *value;
    char **args;
    int  j;

    j = 0;
    key = get_key_in_token(tokens[i]);
    if(!key)
        return 0;
    value = cpp_map_get(g_all.custom_env, key);
    if(!value)
        return 0;
    if(!(tokens[i]->type & e_double_quote))
    {
        args = ft_super_split(value->content, " \t", "");
        if(!args && !args[j])
            return 0;
        add_var_to_tokens(tokens, args, i, j);
    }
    else
        add_var_double_quote_to_tokens(value, i, type);
    return 1;
}

void replace_vars()
{
    t_token **tokens;
    int i;
    int res;

    tokens = g_all.tokens->content;
    i = 0;
    while(g_all.tokens->count > i)
    {
        if(tokens[i]->type & e_var_to_get)
        {
            res = replace_var(tokens, i, get_type_without_set_var(tokens[i]->type));
            if(!res)
                cs_list_delete(g_all.tokens, i--);
            while(res)
                res = replace_var(tokens, i, get_type_without_set_var(tokens[i]->type));
        }
        i++;
    }
}

int is_tokens_has_cmd()
{
    t_token **tokens;
    int i;

    tokens = g_all.tokens->content;
    while(g_all.tokens->count > i)
    {
        if(tokens[i]->type & e_cmd)
            return 0;
        i++;
    }
    return 1;
}

void add_var_to_set()
{
    t_token **tokens;
    int i;
    int set_vars;

    tokens = g_all.tokens->content;
    i = 0;
    set_vars = is_tokens_has_cmd();
    while(g_all.tokens->count > i)
    {
        if((tokens[i]->type & (e_var_to_set | e_set_var)))
        {
            if((tokens[i]->type & e_set_var) || !set_vars)
                cs_list_delete(g_all.tokens, i--);
            else
                add_env_var(tokens[i]->s);
        }
        i++;
    }
}
