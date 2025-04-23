#include "../../mini_shell.h"
#include "split_by_token.h"

int is_char_in_db_quote(t_split_data *data)
{
    if(!data->s[data->i])
        return 0;
    if(data->ch)
        return 1;
    if(!ft_strchr(" |<>\t", data->s[data->i]))
        return 1;
    return 0;
}

int	is_double_quote(t_split_data *data)
{
    if('"' != data->s[data->i])
        return 0;
    data->type = e_args | is_cmd_type() | is_file_name() | e_double_quote;
    g_all.token_str = cpp_str_new();
    if(check_export_cmd(data, "\"export\""))
        return 1;
	while (is_char_in_db_quote(data))
        add_arg_type(data);
    if ((data->type & e_file_name) && (data->type & e_args))
        data->type -= e_args;
    if ((data->type & e_file_name) && (data->type & e_path))
        data->type -= e_path;
    add_token(data);
	return (1);
}

int	is_single_quote(t_split_data *data)
{
    if('\'' != data->s[data->i])
        return 0;
    data->type = e_args | is_cmd_type() | is_file_name() | e_quote;
    g_all.token_str = cpp_str_new();
    if(check_export_cmd(data, "'export'"))
        return 1;
	while (data->s[data->i] && (data->ch || !ft_strchr(" |<>\t", data->s[data->i])))
        add_arg_type(data);
    if ((data->type & e_file_name) && (data->type & e_args))
        data->type -= e_args;
    if ((data->type & e_file_name) && (data->type & e_path))
        data->type -= e_path;
    add_token(data);
	return (1);
}
