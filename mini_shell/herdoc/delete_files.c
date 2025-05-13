/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:42:44 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/13 20:58:31 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

void	clean_files(char **files)
{
	int	i;

	i = 0;
	if (files[i])
	{
		ft_free(files[i]);
		i++;
	}
	cs_list_clear(g_all.files_to_remove);
}

void	delete_files(int flag)
{
	int		i;
	char	**files;
	char	*next_file;

	if (flag == 1)
	{
		files = g_all.files_to_remove->content;
		i = 0;
		while (files[i])
			unlink(files[i++]);
		clean_files(files);
	}
	if (flag == 100)
	{
		next_file = get_cmd_file(1, "/var/tmp/history/cmd_400.txt");
		while (next_file)
		{
			unlink(next_file);
			next_file = get_cmd_file(1, next_file);
			ft_free(next_file);
		}
	}
}
