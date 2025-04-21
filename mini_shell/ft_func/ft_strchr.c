/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:08:47 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/04/21 11:39:11 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] && s[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_strstrchr(const char *s, char *sep)
{
	int i;
	char *str;

	i = 0;
	while (s[i])
	{
		str = ft_strchr(sep, s[i]);
		if (str)
			return &(((char *)s)[i]);
		i++;
	}
	return 0;
}
