#include "../../mini_shell.h"
#include "split_by_token.h"

int is_heredoc_delim(t_split_data *data)
{
	if(!data->s[data->i])
		return 0;
	if(data->ch)
		return 1;
	if(!ft_strchr(" |<>\t", data->s[data->i]))
		return 1;
	return 0;
}

void add_delimiter_char(t_split_data *data)
{
	if (data->s[data->i] == '$' && data->s[data->i + 1] == '$')
	{
		cpp_str_add_char(g_all.token_str, data->s[data->i]);
		data->i++;
	}
	else if(is_dollar_to_skip(data))
		data->i++;
	if(data->ch == '\0' && ft_strchr( "\"'", data->s[data->i]))
		data->ch = data->s[data->i];
	else if(data->ch == data->s[data->i])
		data->ch = '\0';
	else
		cpp_str_add_char(g_all.token_str, data->s[data->i]);
	if (data->type)
	data->i++;
}

int is_delimiter(t_split_data *data)
{
	t_token **tkns;
	t_token *tkn;

	tkns = g_all.tokens->content;
	if(last_cmd_type() != e_heredoc)
		return 0;
    g_all.token_str = cpp_str_new();
	data->first_time = 1;
	data->type = e_delimiter;
	tkn = tkns[g_all.tokens->count - 1];
	tkn->type = tkn->type | e_var_to_get;
	while (is_heredoc_delim(data))
	{
		add_delimiter_char(data);
		if (data->ch)
			tkn->type = e_heredoc;
	}
	add_token(data);
	return 1;
}
