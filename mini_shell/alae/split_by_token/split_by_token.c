/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:44 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 23:02:02 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_by_token.h"

t_token	*create_token(char *s, int type)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->s = s;
	token->type = type;
	return (token);
}

void	skip_space(char *s, int *i)
{
	while (ft_strchr(" \t", s[*i]))
		(*i)++;
}

void	check_tokens(t_split_data *data)
{
	static int	(*func[])(t_split_data *) = {is_redirects_out_append,
		is_redirects_out_truncate, is_redirects_heredoc, is_redirects_input,
		is_pipe, is_delimiter, is_arg, is_expand_variable, is_single_quote,
		is_double_quote, 0};
	int			i;

	i = 0;
	while (func[i])
	{
		if (func[i](data))
			break ;
		i++;
	}
	skip_space(data->s, &data->i);
}

void	add_token(t_split_data *data)
{
	g_all.token = create_token(g_all.token_str->content, data->type);
	cs_list_add(g_all.tokens, (long)g_all.token);
}

void	split_tokens(char *s, char *sep, char *special_sep)
{
	t_split_data	data;

	if (!g_all.tokens)
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
}
