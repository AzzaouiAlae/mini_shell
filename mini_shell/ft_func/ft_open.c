/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:52:58 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/11 05:53:02 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	ft_open(char *file_name, int flag, int perm)
{
	int	fd;

	if (!file_name)
		return (-1);
	fd = open(file_name, flag, perm);
	// write (open("/home/oel-bann/Desktop/sss/mini_shell/f", O_WRONLY | O_APPEND, 0666), file_name, ft_strlen(file_name));
	//  write (open("/home/oel-bann/Desktop/sss/mini_shell/f", O_WRONLY | O_APPEND, 0666), "\n", 1);
	return (fd);
}
