#include "../mini_shell.h"
#include "split_by_token.h"

int	is_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (i);
}

void delimiter_type()
{
	g_all.token->type = e_delimiter;
}

void redir_in_args_type(int count, t_token **tokens)
{
	int type;

	type = tokens[count - 1]->type;
	if(type == e_redir_in || type == e_redir_out_app || 
		type == e_redir_out_trun)
		g_all.token->type = e_file_name;
	else if(type == e_heredoc)
		delimiter_type();
}

int is_file_name_and_redir(t_token **tokens, int count)
{
	int res;

	if(count < 2)
		return 0;
	if(tokens[count - 1]->type & (e_file_name | e_delimiter))
	{
		res = !(count - 2) || tokens[count - 3]->type & e_pipe || 
			tokens[count - 3]->type & e_file_name;
		if(tokens[count - 2]->type & e_redir_out_trun && res)
			return 1;
		if(tokens[count - 2]->type & e_redir_in && res)
			return 1;
		if(tokens[count - 2]->type & e_redir_out_app && res)
			return 1;
		if(tokens[count - 2]->type & e_heredoc && res)
			return 1;
	}
	return 0;
}

void	cmd_path_in_args_type(void)
{
	t_token **tokens;
	int count;
	char *s;
	int res;

	count = g_all.tokens->count;
	tokens = g_all.tokens->content;
	res = is_file_name_and_redir(tokens, count);
	if (count == 0 || tokens[count - 1]->type == e_pipe || res)
	{
		g_all.token->type = g_all.token->type | e_cmd;
		if (ft_strchr(g_all.token_str->content, '/'))
			g_all.token->type = g_all.token->type | e_path;
	}
	s = ft_strchr(g_all.token_str->content, '"');
	if (s && ft_strchr(s + 1, '"'))
		g_all.token->type = g_all.token->type | e_double_quote;
	s = ft_strchr(g_all.token_str->content, '\'');
	if (s && ft_strchr(s + 1, '\''))
		g_all.token->type = g_all.token->type | e_quote;
	if (count)
		redir_in_args_type(count, tokens);
}

void	double_quote_in_args_type(void)
{
	char *s;

	if (ft_strchr(g_all.token_str->content, '"'))
	{
		s = ft_strchr(g_all.token_str->content, '"');
		s = ft_strchr(s, '$');
		if (s && !ft_strchr(" |<>\t$\"", s[1]))
			g_all.token->type = g_all.token->type | e_var_to_get;
	}
}

int double_quote_in_var_to_set(char *str)
{
	char *s;

	s = ft_strchr(str, '"');
	if(!s)
		return 0;
	if(ft_strchr(s + 1, '"'))
		return 1;
	return 0;
}

int	var_to_set_in_arg_type(void)
{
	t_token	**tokens;

	int res, (i) = 0;
	char *s, (ch) = '\0';
	s = g_all.token_str->content;
	ch = '\0';
	tokens = g_all.tokens->content;
	res = !g_all.tokens->count || (tokens[g_all.tokens->count
			- 1]->type & e_set_var);
	while (i < g_all.token_str->count && res)
	{
		if (ch == '\0' && s[i] == '=')
		{
			g_all.token->type = e_var_to_set;
			if(double_quote_in_var_to_set(&(s[i + 1])))
				g_all.token->type =	g_all.token->type | e_double_quote;
			return (1);
		}
		if (ch == '\0' && ft_strchr("\"'", s[i]))
			ch = s[i];
		else if (ch == s[i])
			ch = '\0';
		i++;
	}
	return (0);
}

void	args_type(void)
{
	g_all.token->type = e_args;
	if (!ft_strcmp(g_all.token_str->content, "export") && !g_all.tokens->count)
		g_all.token->type = e_set_var;
	cmd_path_in_args_type();
	double_quote_in_args_type();
	var_to_set_in_arg_type();
}

int cmd_double_quote(t_token **token, int count)
{
	if(count < 2)
		return 0;
	return (token[count - 1]->type & e_file_name && token[count - 2]->type &
		(e_redir_in | e_redir_out_app | e_redir_out_trun) && (!(count - 2) || 
		token[count - 3]->type & e_pipe));
}

void	double_quote_type(void)
{
	t_token **token;
	int count;
	char *s;
	int res;

	res = 0;
	token = g_all.tokens->content;
	count = g_all.tokens->count;
	g_all.token->type = e_double_quote;
	if(!count || token[count - 1]->type & e_pipe || 
			cmd_double_quote(token, count))
		g_all.token->type = g_all.token->type | e_cmd | e_args;
	s = ft_strchr(g_all.token_str->content, '$');
	if(s && !ft_strchr(" |<>\t$\"'", *(s + 1)))
		g_all.token->type = g_all.token->type | e_var_to_get;
	if (count && token[count - 1]->type & (e_cmd | e_args))
		g_all.token->type = g_all.token->type | e_args;
	if(count)
		res = token[count - 1]->type & 
			(e_redir_in | e_redir_out_app | e_redir_out_trun);
	if(res)
		g_all.token->type = g_all.token->type | e_file_name;
	else if (count && token[count - 1]->type == e_heredoc)
		g_all.token->type = g_all.token->type | e_delimiter;
}

void var_to_get_single_char()
{
	t_cs_list *t;
	char *s;
	int res;

	t = g_all.tokens;
	s = g_all.token_str->content;
	res = s[0] == ' ' || s[0] == '\t';
	if(ft_strchr(g_all.token->s, '?'))
		g_all.token->type = e_args | e_error_status;
	else if(g_all.token_str->count - res > 1)
	{
		if (t->count == 0 || (((t_token **)(t->content))[t->count - 1])->type 
		& e_pipe)
			g_all.token->type = e_var_to_get | e_cmd | e_args;
		else
			g_all.token->type = e_var_to_get;
	}
	g_all.token->type = g_all.token->type | e_args;
}

void single_quote_type()
{
	int count;
	t_token **tokens;

	tokens = g_all.tokens->content;
	count = g_all.tokens->count;
	g_all.token->type = e_quote;
	if(!count || cmd_double_quote(tokens, count))
		g_all.token->type = g_all.token->type | e_args | e_cmd;
	if(count)
		g_all.token->type = g_all.token->type | e_args;
}

int is_cmd_in_var_to_set()
{
	int i;
	int len;
	char *s;

	i = 0;
	s =  g_all.token_str->content;
	len = (int)ft_strchrlen(s, '=');
	while(i < len && !ft_strchr(" |<>\t$\"'", s[i]))
		i++;
	return i != len;
}

void var_to_set_type()
{
	if(is_cmd_in_var_to_set())
		g_all.token->type = e_cmd | e_args;
	else
		g_all.token->type = e_var_to_set;
}

void	get_type(t_token_type type)
{
	if(type & e_var_to_get)
		var_to_get_single_char();
	else if (type & e_args)
		args_type();
	else if(type & e_double_quote)
		double_quote_type();
	else if(type & e_quote)
		single_quote_type();
	else if(type & e_var_to_set)
		var_to_set_type();
	else
		g_all.token->type = type;
}

void	add_cmd(char ch, t_token_type new_token)
{
	if (g_all.tokens == NULL)
		g_all.tokens = cs_list_new(sizeof(t_token *));
	if (new_token)
	{
		if (g_all.token_str && !is_all_space(g_all.token_str->content))
		{
			g_all.token = ft_calloc(1, sizeof(t_token));
			g_all.token->s = g_all.token_str->content;
			get_type(g_all.last_cmd_type);
			cs_list_add(g_all.tokens, (long)g_all.token);
		}
		g_all.token_str = cs_list_new(1);
		g_all.last_cmd_type = new_token;
	}
	cs_list_add(g_all.token_str, ch);
}

void	skip_space(char *s, int *i)
{
	while (ft_strchr(" \t", s[*i]))
		(*i)++;
}

int	is_redirects_out_append(t_split_data *data)
{
	if (data->s[data->i] == '>' && data->s[data->i + 1] == '>')
	{
		add_cmd(data->s[data->i], e_redir_out_app);
		add_cmd(data->s[data->i + 1], 0);
		return (1);
	}
	return (0);
}

int	is_redirects_out_truncate(t_split_data *data)
{
	if (data->s[data->i] == '>')
	{
		add_cmd(data->s[data->i], e_redir_out_trun);
		return (1);
	}
	return (0);
}

int	is_redirects_heredoc(t_split_data *data)
{
	if (data->s[data->i] == '<' && data->s[data->i + 1] == '<')
	{
		add_cmd(data->s[data->i], e_heredoc);
		add_cmd(data->s[data->i + 1], 0);
		return (1);
	}
	return (0);
}

int	is_redirects_in_file(t_split_data *data)
{
	if (data->s[data->i] == '<')
	{
		add_cmd(data->s[data->i], e_redir_in);
		return (1);
	}
	return (0);
}

int	is_pipe(t_split_data *data)
{
	if (data->s[data->i] == '|')
	{
		add_cmd(data->s[data->i], e_pipe);
		return (1);
	}
	return (0);
}

void space_in_var_to_get(t_split_data *data)
{
	t_token	**tokens;

	tokens = g_all.tokens->content;
	if(g_all.last_cmd_type & e_heredoc)
	{
		add_cmd(data->s[data->i], e_delimiter);
		return ;
	}
	if(data->i && !ft_strchr(" |<>\t", data->s[data->i - 1]))
	{
		g_all.last_cmd_type = e_var_to_get | g_all.last_cmd_type;
		add_cmd(data->s[data->i], 0);
	}
	else
		add_cmd(data->s[data->i], e_var_to_get);
}

int	is_exp_var(t_split_data *data)
{
	if (data->s[data->i] == '$')
	{
		space_in_var_to_get(data);
		data->i++;
		if(data->s[data->i] == '?')
		{
			add_cmd('?', 0);
			data->i++;
			if(ft_strchr("\t ", data->s[data->i + 1]))
			{
				add_cmd(' ', 0);
				data->i++;
			}
			return 1;
		}
		while (data->s[data->i] && !ft_strchr(data->sep, data->s[data->i]) && 
			!ft_strchr(data->special_sep, data->s[data->i]))
		{
			add_cmd(data->s[data->i], 0);
			data->i++;
		}
		return (1);
	}
	return (0);
}

int	is_single_quote(t_split_data *data)
{
	if (data->s[data->i] == '\'')
	{
		if (ft_strchr(data->sep, data->s[data->i - 1]))
			add_cmd(data->s[data->i], e_quote);
		else
			add_cmd(data->s[data->i], 0);
		g_all.last_cmd_type = g_all.last_cmd_type | e_quote;
		data->i++;
		while (data->s[data->i] && (data->first_time || data->s[data->i
				- 1] != '\''))
		{
			add_cmd(data->s[data->i], 0);
			data->first_time = 0;
			data->i++;
		}
		return (1);
	}
	return (0);
}

int	is_double_quote(t_split_data *data)
{
	if (data->s[data->i] == '"')
	{
		if (!data->i || ft_strchr(data->sep, data->s[data->i - 1]))
			add_cmd(data->s[data->i], e_double_quote);
		else
			add_cmd(data->s[data->i], 0);
			g_all.last_cmd_type = g_all.last_cmd_type | e_double_quote;
		data->i++;
		while (data->s[data->i] && (data->first_time || data->s[data->i
				- 1] != '"'))
		{
			add_cmd(data->s[data->i], 0);
			data->first_time = 0;
			data->i++;
		}
		return (1);
	}
	return (0);
}

void arg_type_quote(t_split_data *data)
{
	if(!data->i || !ft_strchr("\"'", data->s[data->i - 1]))
		add_cmd(data->s[data->i], e_args);
	else
		add_cmd(data->s[data->i], 0);
}

int	is_arg(t_split_data *data)
{
	data->first_time = 1;
	while (data->s[data->i] && !ft_strchr(data->sep, data->s[data->i])
		&& !ft_strchr(data->special_sep, data->s[data->i]))
	{
		if (data->first_time)
			arg_type_quote(data);
		else
			add_cmd(data->s[data->i], 0);
		data->first_time = 0;
		data->i++;
	}
	return (!data->first_time);
}

int is_delimiter(t_split_data *data)
{
	if(g_all.last_cmd_type != e_heredoc)
		return 0;
	data->first_time = 1;
	if(data->s[data->i] == '$' && ft_strchr("\"'", data->s[data->i + 1]))
		data->i++;
	while (data->s[data->i] && (data->ch || !ft_strchr(" |<>\t", data->s[data->i])))
	{
		if(data->ch == '\0' && ft_strchr( "\"'", data->s[data->i]))
			data->ch = data->s[data->i];
		else if(data->ch == data->s[data->i])
			data->ch = '\0';
		else
		{
			if(data->first_time)
			{
				add_cmd(data->s[data->i], e_delimiter);
				data->first_time = 0;
			}
			else
				add_cmd(data->s[data->i], 0);
		}
		data->i++;
	}
	return 1;
}

void	check_tokens(t_split_data *data)
{
	if(is_delimiter(data))
		;
	if (is_arg(data))
		;
	else if (is_redirects_out_append(data))
		(data->i) += 2;
	else if (is_redirects_out_truncate(data))
		(data->i)++;
	else if (is_redirects_heredoc(data))
		(data->i) += 2;
	else if (is_redirects_in_file(data))
		(data->i)++;
	else if (is_pipe(data))
		(data->i)++;
	else if (is_exp_var(data))
		;
	else if (is_single_quote(data))
		;
	else
		is_double_quote(data);
	skip_space(data->s, &data->i);
}

void split_tokens(char *s, char *sep, char *special_sep)
{
	t_split_data	data;

	if(!g_all.tokens)
		g_all.tokens = cs_list_new(sizeof(t_token *));
	else
		cs_list_clear(g_all.tokens);
	data.i = 0;
	data.ch = '\0';
	data.s = s;
	data.sep = sep;
	data.special_sep = special_sep;
	while (ft_strchr(" \t", s[data.i]))
		data.i++;
	while (s[data.i])
		check_tokens(&data);
	add_cmd(' ', 1);
}
