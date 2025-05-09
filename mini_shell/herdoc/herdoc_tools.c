/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:47:57 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/08 11:46:14 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

int	count_here_doc(void)
{
	t_token	**tokens;

	int herdoc_count, (i) = 0;
	herdoc_count = 0;
	tokens = g_all.tokens->content;
	while (tokens[i] && i < g_all.error_i)
	{
		if (tokens[i + 1] && (tokens[i]->type & e_heredoc)
			&& (tokens[i + 1]->type & e_delimiter))
			herdoc_count++;
		i++;
	}
	return (herdoc_count);
}

char	*get_line(char *input, int flag)
{
	static int	fd;

	if (flag == 1)
	{
		fd = open("/tmp/temp.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
		if (fd == -1)
			return (NULL);
		ft_putstr_fd(fd, input, 0);
		ft_close(fd);
		fd = open("/tmp/temp.txt", O_RDWR, 0666);
		get_next_line(fd);
	}
	else if (flag == 2)
	{
		ft_close(fd);
		unlink("/tmp/temp.txt");
	}
	else
		return (get_next_line(fd));
	return (NULL);
}
