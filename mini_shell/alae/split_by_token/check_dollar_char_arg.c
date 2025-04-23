#include "split_by_token.h"

void add_dollar_arg_token(t_split_data *data)
{
    g_all.token_str = cpp_str_new();
    cpp_str_add_char(g_all.token_str, '$');
    g_all.token = create_token(g_all.token_str->content, data->type);
    cs_list_add(g_all.tokens, (long)g_all.token);
    data->i++;
}

int is_dollar_to_add(t_split_data *data)
{
    if(data->s[data->i] != '$')
        return 0;
    if (ft_strchr(" |<>\t", data->s[data->i + 1]))
        return 1;
    if (!data->s[data->i + 1])
        return 1;
    return 0;
}

int is_dollar_to_skip(t_split_data *data)
{
    if(data->ch)
        return 0;
    if(data->s[data->i] != '$')
        return 0;
    if (!ft_strchr("\"'", data->s[data->i + 1]))
        return 0;
    return 1;
}

int check_dollar_ch_arg(t_split_data *data)
{
    if (is_dollar_to_add(data))
    {
        add_dollar_arg_token(data);
        return 1;
    }
    if(is_dollar_to_skip(data))
        data->i++;
    return 0;
}

int is_dollar_char(t_split_data *data)
{
    int i;
    char *s;

    i = data->i;
    s = data->s;
    if(data->ch == '"' && s[i] == '$' && s[i + 1] == data->ch)
        return (1);
    if(!data->ch && s[i] == '$' && (ft_strchr("\"'", s[i + 1]) || !s[i + 1]))
        return (1);
    return 0;
}
