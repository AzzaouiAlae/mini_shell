/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 05:32:49 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 15:47:38 by aazzaoui         ###   ########.fr       */
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
			str = get_next_line(fd);
			i = -1;
		}
		i++;
	}
}
