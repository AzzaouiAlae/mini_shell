#include "split_by_token.h"

int is_str_cmd(t_split_data *data, char *s)
{
    if(ft_strncmp(s, &(data->s[data->i]), ft_strlen(s)))
        return 0;
    if(!(data->type & e_cmd))
        return 0;
    return 1;
}

int check_export_cmd(t_split_data *data, char *export)
{
    if(is_str_cmd(data, export))
    {
        cpp_str_add(g_all.token_str, "export");
        g_all.token = create_token(g_all.token_str->content, e_set_var | e_cmd);
        cs_list_add(g_all.tokens, (long)g_all.token);
        data->i += ft_strlen(export);
        return 1;
    }
    return 0;
}

int is_var_to_get(t_split_data *data)
{
    if(data->ch == '\'')
        return 0;
    if(data->s[data->i] != '$')
        return 0;
    if(ft_strchr(" |<>\t", data->s[data->i + 1]))
        return 0;
    if(is_dollar_char(data))
        return 0;
    return 1;
}
