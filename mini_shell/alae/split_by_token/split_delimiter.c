#include "../../mini_shell.h"
#include "split_by_token.h"

int is_delimiter(t_split_data *data)
{
	if(last_cmd_type() != e_heredoc)
		return 0;
    g_all.token_str = cpp_str_new();
	data->first_time = 1;
	while (data->s[data->i] && (data->ch || !ft_strchr(" |<>\t", data->s[data->i])))
	{
		if(data->s[data->i] == '$' && ft_strchr("\"'", data->s[data->i + 1]))
			data->i++;
		if(data->ch == '\0' && ft_strchr( "\"'", data->s[data->i]))
			data->ch = data->s[data->i];
		else if(data->ch == data->s[data->i])
			data->ch = '\0';
		else
			cpp_str_add_char(g_all.token_str, data->s[data->i]);
		data->i++;
	}
    g_all.token = create_token(g_all.token_str->content, e_delimiter);
	cs_list_add(g_all.tokens, (long)g_all.token);
	return 1;
}
