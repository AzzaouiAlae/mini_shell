/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_name_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:33:14 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/27 23:22:23 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

char	*create_file_name(void)
{
	char	*file;

	file = ft_strdup("/tmp/file_0000.txt");
	while (1)
	{
		if (access(file, F_OK))
			return (file);
		if (file[13] != '9')
			file[13] = file[13] + 1;
		else if (file[12] != '9')
		{
			file[12] = file[12] + 1;
			file[13] = '0';
		}
		else if (file[11] != '9')
		{
			file[11] = file[11] + 1;
			file[12] = '0';
			file[13] = '0';
		}
	}
	free(file);
	return (NULL);
}
