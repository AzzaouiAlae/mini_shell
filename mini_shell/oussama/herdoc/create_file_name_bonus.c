/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_name_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:33:14 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/18 12:44:09 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

char	*create_file_name(void)
{
	char	*file;

	file = ft_strdup("file_0000.txt");
	while (1)
	{
		if (access(file, F_OK))
			return (file);
		if (file[8] != '9')
			file[8] = file[8] + 1;
		else if (file[7] != '9')
		{
			file[7] = file[7] + 1;
			file[8] = '0';
		}
		else if (file[6] != '9')
		{
			file[6] = file[6] + 1;
			file[7] = '0';
			file[8] = '0';
		}
	}
}
