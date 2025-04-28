#include "get_env_vars.h"

int	del_set_var(int type)
{
	if (type & e_var_to_get)
		return (type - e_var_to_get);
	return (type);
}

void	copy_char_to_new_str(t_cpp_str *str, t_cpp_str *new_str_token, char *ch)
{
	char	first_char;

	first_char = str->content[0];
	if (!(*ch) && (first_char == '\'' || first_char == '"'))
		*ch = first_char;
	else if (*ch == first_char)
		*ch = '\0';
	cpp_str_add_char(new_str_token, first_char);
	cpp_str_delete_char(str, 0);
}

int	is_key_char(t_cpp_str *str, int first_time)
{
	if (!str->content[0])
		return (0);
	if (str->content[0] == '?')
		return (1);
	if (!is_valid_var_name_char(str->content[0]))
		return (0);
	if (first_time && str->content[0] == '$')
		return (1);
	if (!ft_strchr(" |<>\t$\"'=", str->content[0]))
		return (1);
	return (0);
}

int	create_str_key(t_cpp_str *str, t_cpp_str *key, int is_digt)
{
	char	ch;

	ch = str->content[0];
	if (ch == '$' || ch == '?')
	{
		cpp_str_add_char(key, ch);
		cpp_str_delete_char(str, 0);
		return (1);
	}
	cpp_str_add_char(key, ch);
	cpp_str_delete_char(str, 0);
	if (is_digt && !is_digit(str->content[0]))
		return (1);
	return (0);
}

char	*create_key_token(t_cpp_str *str, t_cpp_str *new_str_token,
		t_get_env_data *data)
{
	int			is_digt;
	int			first_time;
	t_cpp_str	*key;

	is_digt = 0;
	key = cpp_str_new();
	first_time = 1;
	while (!is_var_start(str, data->ch, data))
		copy_char_to_new_str(str, new_str_token, &data->ch);
	if (str->content[0] == '$')
		cpp_str_delete_char(str, 0);
	if (is_digit(str->content[0]))
		is_digt = 1;
	while (is_key_char(str, first_time))
	{
		if (create_str_key(str, key, is_digt))
			return (key->content);
		first_time = 0;
	}
	return (key->content);
}
