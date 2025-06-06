/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:43:31 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/11 05:53:36 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	ft_close(int fd)
{
	if (fd >= 0)
		close(fd);
}
