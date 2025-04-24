/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:06:05 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/04/24 14:20:16 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 && s2 || s1 && !s2)
		return (1);
	if (!s1 && !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	size_t	i;

	i = 0;
	if (!s1 && s2 || s1 && !s2)
		return (1);
	if (!s1 && !s2)
		return (0);
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
