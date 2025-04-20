#include "../../mini_shell.h"
#include "split_by_token.h"

int	is_single_quote(t_split_data *data)
{
    int type;

    if('\'' != data->s[data->i])
        return 0;
    type = e_args | is_cmd_type() | is_file_name() | e_quote;
    g_all.token_str = cpp_str_new();
    if(!ft_strcmp2("'export'", data->s) && (type & e_cmd))
    {
        cpp_str_add(g_all.token_str, "export");
        g_all.token = create_token(g_all.token_str->content, e_set_var);
        cs_list_add(g_all.tokens, (long)g_all.token);
        data->i += 8;
        return 1;
    }
	while (data->s[data->i] && (data->ch || !ft_strchr(" |<>\t", data->s[data->i])))
        add_arg_type(data, &type);
    if (type & e_file_name)
        type = e_file_name | e_quote;
    g_all.token = create_token(g_all.token_str->content, type);
    cs_list_add(g_all.tokens, (long)g_all.token);
	return (1);
}
