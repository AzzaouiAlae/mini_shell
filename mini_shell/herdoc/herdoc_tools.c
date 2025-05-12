/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:47:57 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 05:28:02 by oel-bann         ###   ########.fr       */
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
		fd = ft_open("/tmp/temp.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
		if (fd == -1)
			return (NULL);
		ft_putstr_fd(fd, input, 0);
		ft_close(fd);
		fd = ft_open("/tmp/temp.txt", O_RDWR, 0666);
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

void	exit_her_doc(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	g_all.cmd_error_status = 130;
	ft_exit(g_all.cmd_error_status);
}

int	is_token(t_her_doc her_doc)
{
	if (!(her_doc.tokens[her_doc.i]))
		return (0);
	if (!(her_doc.i < g_all.error_i))
		return (0);
	if (g_all.ctrl_c)
		return (0);
	return (1);
}

int	create_here_doc_file(t_her_doc *her_doc)
{
	her_doc->file_name = create_file_name();
	cs_list_add(g_all.files_to_remove, (long)her_doc->file_name);
	her_doc->fd = ft_open(her_doc->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (her_doc->fd == -1)
	{
		g_all.cmd_error_status = 127;
		write(2, "ERROR HERDOC FILE CAN'T OPEN\n", 29);
		return (0);
	}
	return (1);
}
