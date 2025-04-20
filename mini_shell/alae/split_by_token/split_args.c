#include "../../mini_shell.h"
#include "split_by_token.h"

int is_dollar_char_arg(t_split_data *data, int *type)
{
    int i;
    char *s;

    i = data->i;
    s = data->s;
    if (s[i] == '$' && (ft_strchr(" |<>\t", s[i + 1]) || !s[i + 1] ))
    {
        g_all.token_str = cpp_str_new();
        cpp_str_add_char(g_all.token_str, '$');
        g_all.token = create_token(g_all.token_str->content, *type);
        cs_list_add(g_all.tokens, (long)g_all.token);
        data->i++;
        return 1;
    }
    if(!data->ch && s[i] == '$' && (ft_strchr("\"'", s[i + 1])))
        data->i++;
    return 0;
}

int is_double_quote_after_dollar_char(t_split_data *data, int *type)
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

void add_arg_type(t_split_data *data, int *type)
{
    if(data->ch != '\'' && data->s[data->i] == '$' &&
        !ft_strchr(" |<>\t", data->s[data->i + 1]) &&
        !is_double_quote_after_dollar_char(data, type))
        *type = *type | e_var_to_get;
    else if(!data->ch && ft_strchr("\"'", data->s[data->i]))
    {
        data->ch = data->s[data->i];
        if(data->ch == '\'')
            *type = *type | e_quote;
        else if (data->ch == '"')
            *type = *type | e_double_quote;
    }
    else if (data->ch == data->s[data->i])
        data->ch = '\0';
    else if(!(*type & e_path) && data->s[data->i] == '/')
        *type = *type | e_path;
    cpp_str_add_char(g_all.token_str, data->s[data->i]);
    data->i++;
}

void is_var_to_set(t_split_data *data, int *type)
{
    t_token *token;
    char *s;
    int i;

    if(g_all.tokens->count)
        token = ((t_token **)(g_all.tokens->content))[g_all.tokens->count - 1];
    if(!g_all.tokens->count || (token->type & e_set_var))
    {
        s = ft_strchr(" |<>\t\"'$=", data->s[data->i]);
        i = -1;
        while (!s)
            s = ft_strchr(" |<>\t\"'$=", data->s[data->i + (++i)]);
        if(s && *s == '=')
            *type = e_var_to_set;
    }
}

int	is_arg(t_split_data *data)
{
    int type;

    type = e_args | is_cmd_type() | is_file_name();
    if(is_dollar_char_arg(data, &type))
        return 1;
    if(ft_strchr(" |<>\t\"'$", data->s[data->i]))
        return 0;
    g_all.token_str = cpp_str_new();
    if(!ft_strcmp2("export", &(data->s[data->i])) && (type & e_cmd))
    {
        cpp_str_add(g_all.token_str, "export");
        g_all.token = create_token(g_all.token_str->content, e_set_var | e_cmd);
        cs_list_add(g_all.tokens, (long)g_all.token);
        data->i += 6;
        return 1;
    }
    is_var_to_set(data, &type);
	while (data->s[data->i] && (data->ch || !ft_strchr(" |<>\t", data->s[data->i])))
        add_arg_type(data, &type);
    if (type & e_file_name)
        type = e_file_name;
    g_all.token = create_token(g_all.token_str->content, type);
    cs_list_add(g_all.tokens, (long)g_all.token);
	return (1);
}
