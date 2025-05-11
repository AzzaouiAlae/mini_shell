/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:44:16 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/11 05:06:20 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	add_the_past_history(void)
{
	char	*file_name;
	char	full_cmd[204800];

	int fd, (cread) = 0;
	file_name = get_cmd_file(1, "/var/tmp/history/cmd_00/.txt");
	while (file_name)
	{
		fd = ft_open(file_name, O_RDONLY, 0666);
		if (fd == -1)
			return ;
		cread = read(fd, full_cmd, sizeof(full_cmd) - 1);
		if (cread == -1)
		{
			ft_close(fd);
			break ;
		}
		full_cmd[cread] = '\0';
		ft_close(fd);
		add_history((const char *)full_cmd);
		file_name = get_cmd_file(0, NULL);
	}
}

void	free_for_new_cmds(void)
{
	char	full_cmd[204800];

	char *before, *(after);
	int fd_before, (fd_after) = 0, (cread);
	cread = 0;
	fd_before = 0;
	if (access("/var/tmp/history/cmd_500.txt", F_OK) == 0)
	{
		before = get_cmd_file(1, "/var/tmp/history/cmd_00/.txt");
		after = get_cmd_file(1, "/var/tmp/history/cmd_099.txt");
		while (after)
		{
			fd_after = ft_open(after, O_RDONLY, 0666);
			cread = read(fd_after, full_cmd, sizeof(full_cmd) - 1);
			full_cmd[cread] = '\0';
			ft_close(fd_after);
			fd_before = ft_open(before, O_RDWR | O_TRUNC, 0666);
			ft_putstr_fd(fd_before, full_cmd, 0);
			ft_close(fd_before);
			before = get_cmd_file(1, before);
			after = get_cmd_file(1, after);
		}
		delete_files(100);
		rl_clear_history();
		add_the_past_history();
	}
}

void	add_new_cmd_history(char *input, int new)
{
	int		fd;
	char	*new_input;

	new_input = replace_char(ft_strdup(input), '\n', '\0');
	free_for_new_cmds();
	if (!g_all.current_cmd_file)
		g_all.current_cmd_file = create_cmd_file();
	if (new == 1)
	{
		fd = ft_open(g_all.current_cmd_file, O_CREAT | O_RDWR, 0666);
		ft_putstr_fd(fd, new_input, 0);
		ft_close(fd);
		add_history(new_input);
	}
	else
	{
		fd = ft_open(g_all.current_cmd_file, O_RDWR | O_APPEND, 0666);
		ft_putstr_fd(fd, "\n", 1);
		ft_putstr_fd(fd, new_input, 0);
		ft_close(fd);
		rl_clear_history();
		add_the_past_history();
	}
}
