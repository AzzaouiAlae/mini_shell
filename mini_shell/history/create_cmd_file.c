/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:33:14 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/10 22:37:18 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

char	*create_cmd_file(void)
{
	char	*file;

	file = ft_strdup("/var/tmp/history/cmd_000.txt");
	while (1)
	{
		if (access(file, F_OK))
			return (file);
		if (file[23] != '9')
			file[23] = file[23] + 1;
		else if (file[22] != '9')
		{
			file[22] = file[22] + 1;
			file[23] = '0';
		}
		else if (file[21] != '9')
		{
			file[21] = file[21] + 1;
			file[22] = '0';
			file[23] = '0';
		}
	}
	return (NULL);
}

char	*get_cmd_file(int reset, char *file_to_start)
{
	static char	*current_file;
	int			fd;

	if (reset == 1)
		current_file = ft_strdup(file_to_start);
	if (current_file[23] != '9')
		current_file[23] = current_file[23] + 1;
	else if (current_file[22] != '9')
	{
		current_file[22] = current_file[22] + 1;
		current_file[23] = '0';
	}
	else if (current_file[21] != '9')
	{
		current_file[21] = current_file[21] + 1;
		current_file[22] = '0';
		current_file[23] = '0';
	}
	fd = ft_open(current_file, O_RDONLY, 0666);
	if (fd != -1)
	{
		ft_close(fd);
		return (ft_strdup(current_file));
	}
	return (NULL);
}
