/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:09:52 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/01 12:43:54 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line_verifier(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*my_ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	int lenstr, (i), (y);
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lenstr = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(1, lenstr + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}