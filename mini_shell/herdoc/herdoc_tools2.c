/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 05:32:49 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/13 00:19:26 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

int	is_heredoc_token(t_her_doc her_doc)
{
	if (!(her_doc.tokens[her_doc.i + 1]))
		return (0);
	if (!(her_doc.tokens[her_doc.i]->type & e_heredoc))
		return (0);
	if (!(her_doc.tokens[her_doc.i + 1]->type & e_delimiter))
		return (0);
	return (1);
}

void	read_first_line(int fd)
{
	char	*str;
	char	ch;
	int		i;

	ch = '\0';
	i = 0;
	str = get_next_line(fd);
	while (str && str[i])
	{
		if (!ch && ft_strchr("\"'", str[i]))
			ch = str[i];
		else if (ch == str[i])
			ch = '\0';
		else if (ch && !str[i + 1])
		{
			ft_free(str);
			str = get_next_line(fd);
			i = -1;
		}
		i++;
	}
	ft_free(str);
}

void	clear_heredoc_tokens(int i)
{
	t_token	**tokens;
	t_token	*tkn;

	tokens = g_all.tokens->content;
	tkn = tokens[i + 1];
	ft_free(tkn->s);
	ft_free(tkn);
	cs_list_delete(g_all.tokens, i + 1);
	tkn = tokens[i + 1];
	ft_free(tkn->s);
	ft_free(tkn);
	cs_list_delete(g_all.tokens, i + 1);
}
