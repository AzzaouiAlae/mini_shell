#include "../../mini_shell.h"
#include "split_by_token.h"

int	is_expand_variable(t_split_data *data)
{
	int type;

    if(data->s[data->i] != '$')
        return 0;
    type = e_args | is_cmd_type() | is_file_name();
    g_all.token_str = cpp_str_new();
    while(data->s[data->i] && (data->ch || !ft_strchr(" |<>\t", data->s[data->i])))
        add_arg_type(data, &type);
    if (type & e_file_name)
        type = e_file_name | e_var_to_get;
    g_all.token = create_token(g_all.token_str->content, type);
    cs_list_add(g_all.tokens, (long)g_all.token);
	return (1);
}
