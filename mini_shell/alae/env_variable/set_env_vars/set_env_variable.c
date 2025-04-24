#include "set_env_vars.h"

t_cs_list	*create_value_list(char *s, int *val_len, int type)
{
	t_cs_list	*str;
	char		ch;
	int			i;

	i = 1;
	str = cs_list_new_capacity(1, ft_strlen(s));
	ch = '\0';
	while (s[i])
	{
		if (ch == '\0' && (s[i] == '\"' || s[i] == '\''))
			ch = s[i];
		else if (s[i] == '\"' || s[i] == '\'')
			ch = '\0';
		else
			cs_list_add(str, s[i]);
		i++;
	}
    str->type = type;
	return (str);
}

void	add_env_var(char *kvp, int type)
{
	t_cpp_str *str_key;
	t_cpp_str *str_val;
    t_cs_list *val_list;
	t_cs_list *val;
    int val_len;
    int key_len;
    char *s;

	s = str_find_char(kvp, "+=");
	if (!s)
		return ;
    key_len = ft_strlen_delimiter(kvp, "+=");
    str_key = cpp_str_new();
    str_val = cpp_str_new();
	cpp_str_add_len(str_key, kvp, key_len);
	if (*s == '+')
	{
		val_list = cpp_map_get(g_all.custom_env, str_key->content);
		s++;
		val = create_value_list(s, &val_len, type);
		cs_list_add_range(val_list, val->count, val->content);		
	}
	else
		val_list = create_value_list(s, &val_len, type);
	cpp_map_add(g_all.custom_env, str_key->content, val_list);
}

void print_export_error(t_set_env_vars *data)
{
	t_token *tkn;
	t_cpp_str *str;

	str = cpp_str_new();
    tkn = data->tokens[data->i];
	cpp_str_add(str, "mini-shell: export: `");
	cpp_str_add(str, tkn->s);
	cpp_str_add(str, "': not a valid identifier\n");
	write(2, str->content, str->count);
	g_all.cmd_error_status = 1;
	cs_list_delete(g_all.tokens, data->i);
    data->i--;
}

void	add_var_to_env(t_set_env_vars *data)
{
    t_token *tkn;

    tkn = data->tokens[data->i];
	if (is_env_var(data))
	{
		if ((tkn->type & e_set_var))
            data->is_export_args = 1;
		else
			add_env_var(data->tokens[data->i]->s, data->type);
		cs_list_delete(g_all.tokens, data->i);
        data->i--;
	}
	else
	{
		if(data->is_export_args)
			print_export_error(data);
		else
			tkn->type = e_args | is_cmd_type() | is_file_name() | is_path(tkn->s);
	}
}

void	add_vars_to_env(void)
{
    t_set_env_vars data;

	ft_bzero(&data, sizeof(t_set_env_vars));
	data.has_cmd = is_tokens_has_cmd();
	data.tokens = g_all.tokens->content;
    data.count = g_all.tokens->count;
	while (g_all.tokens->count > data.i && !(data.has_cmd))
	{
		add_var_to_env(&data);
		data.i++;
	}
    if(data.count == 1 && data.is_export_args && !data.has_cmd)
        print_env_vars();
}
