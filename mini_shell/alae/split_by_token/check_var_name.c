#include "split_by_token.h"

int is_alpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z');
}

int is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int is_valid_var_name_char(char ch)
{
    if(!is_alpha(ch) && !is_digit(ch) && ch != '_' && ch != '?')
        return 0;
    return 1;
}

int is_valid_var_name(char *str)
{
    int i;

    i = 1;
    if(!is_alpha(str[0]) && str[0] != '_')
        return 0;
    while(str[i] && !ft_strchr(" |<>\t\"'=+", str[i]))
    {
        if(!is_valid_var_name_char(str[i]) && str[i] != '$' && str[i] != '?')
            return 0;
        i++;
    }
    return 1;
}

int is_var_to_set(t_split_data *data)
{
    int res;
    char *s;
    t_token *token;

    s = str_find_char(&(data->s[data->i]), " |<>\t\"'=+"); 
    res = is_valid_var_name(&(data->s[data->i])) && s &&
        (*s == '=' || (*s == '+' && *(s + 1) == '='));
    if(!res)
        return 0;
    if(!g_all.tokens->count)
        return 1;
    token = ((t_token **)(g_all.tokens->content))[g_all.tokens->count - 1];
    if((token->type & e_set_var))
        return 1;
    return 0;
}
