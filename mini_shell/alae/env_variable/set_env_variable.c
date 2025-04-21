#include "env_var.h"

int is_tokens_has_cmd()
{
    t_token **tokens;
    int i;

    i = 0;
    tokens = g_all.tokens->content;
    while(g_all.tokens->count > i)
    {
        if((tokens[i]->type & e_cmd) && !(tokens[i]->type & e_set_var))
            return 0;
        i++;
    }
    return 1;
}

t_cs_list *create_value_list(char *s, int *value_len)
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
    t_cpp_str *str_key;
    t_cs_list *value_list;
    int value_len;
    int key_len;
    char *s;

    s = ft_strstrchr(kvp, "+=");
    key_len = ft_strstrlen(kvp, "+=");
    str_key = cpp_str_new();
    cpp_str_add_len(str_key, kvp, key_len);
    value_list = create_value_list(s, &value_len);
    cpp_map_add(g_all.custom_env, str_key->content, value_list);
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
