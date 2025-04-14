/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_list_contains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:42:53 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/03/23 15:48:13 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs_list.h"

int	cs_list_contains_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	cs_list_contains_int(int *nums, int count, int num)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (nums[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	cs_list_contains_long(long *nums, int count, long num)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (nums[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	cs_list_contains(t_cs_list *list, long item)
{
	if (!list)
		return (0);
	if (list->size_of_type == 1)
		return (cs_list_contains_char(list->content, (char)item));
	else if (list->size_of_type == 4)
		return (cs_list_contains_int(list->content, list->count, (int)item));
	else if (list->size_of_type == 8)
		return (cs_list_contains_long(list->content, list->count, item));
	return (0);
}
