/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:42:08 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/27 16:42:09 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	s = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strdup_without_save_mem(const char *s1)
{
	int		i;
	char	*s;
	size_t	len;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	s = (char *)ft_calloc_without_save(sizeof(char), (len + 1));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
