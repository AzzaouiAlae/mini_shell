#include "get_env_vars.h"

int init_vars(char *ch1, char *ch2, t_cpp_str *str)
{
    if (str->count)
        *ch1 = str->content[str->count - 1];
    else
        *ch1 = 0;
    if (str->count > 1)
        *ch2 = str->content[str->count - 2];
    else
        *ch2 = 0;
}

int is_var_start(t_cpp_str *str, char ch, t_get_env_data *data)
{
    char c;
    char c2;

    init_vars(&c, &c2, data->new_str_token);
    if (!str->content[0])
        return 1;
    if (ch == data->special_ch)
        return 0;
    if (str->content[0] == '$' && str->content[1] == '$')
    {
        copy_char_to_new_str(str, data->new_str_token, &ch);
        return 0;
    }
    if (str->content[0] == '$' && ft_strchr("\"' ", str->content[1]))
        return 0;
    if (str->content[0] == '$' && str->content[1] == '\0')
        return 0;
    if(str->content[0] == '$' && !is_valid_var_name_char(str->content[1]))
        return 0;
    if(str->content[0] != '$')
        return 0;
    return 1;
}

void create_value_token(t_get_env_data *data)
{
    t_cs_list *value;
    char *key;
    int first_time;

    first_time = 1;
    value = NULL;
    data->ch = '\0';
    while(first_time || key[0])
    {
        key = create_key_token(data->str_token, data->new_str_token, data);
        if(key && key[0])
        {
            value = cpp_map_get(g_all.custom_env, key);
            if(value)
                cpp_str_add(data->new_str_token, value->content);
        }
        else
            return ;
        first_time = 0;
    }
}

int cmd_type(int i)
{
	t_token **tokens;

    tokens = g_all.tokens->content;
    while (i && !(tokens[i]->type & e_pipe))
        i--;
	while(i < g_all.tokens->count)
	{
		if (tokens[i]->type & e_cmd)
			return 0;
		if (tokens[i]->type & e_pipe)
			return e_cmd;
		i++;
	}
	return e_cmd;
}

int get_variable_value(t_get_env_data *data)
{
    data->new_str_token = cpp_str_new();
    data->str_token = cpp_str_new_substitute(data->tokens[data->i]->s);
    create_value_token(data);
    data->args = split_var_token(data->new_str_token);
    if(!data->args || !data->args[0])
    {
        cs_list_delete(g_all.tokens, data->i);
        if (!g_all.tokens->count || !(data->tokens[data->i]))
            return 0;
        data->tokens[data->i]->type = data->tokens[data->i]->type | 
        cmd_type(data->i);
        data->i--;
        return 0;
    }
    add_var_to_tokens(data);
    return 1;
}

void get_variables_value()
{
    t_get_env_data data;

    ft_bzero(&data, sizeof(t_get_env_data));
    data.special_ch = '\'';
    data.tokens = g_all.tokens->content;
    while(g_all.tokens->count > data.i)
    {
        if (data.tokens[data.i]->type & e_file_name)
            cs_list_add(g_all.variables_name, (long)ft_strdup(data.tokens[data.i]->s));
        if(data.tokens[data.i]->type & e_var_to_get)
        {
            data.type = data.tokens[data.i]->type;
            cs_list_clear(g_all.ch_i);
            get_variable_value(&data);
        }
        data.i++;
    }
}
