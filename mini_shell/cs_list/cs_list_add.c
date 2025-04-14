/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:44:04 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/03/23 15:48:13 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs_list.h"

void	cs_list_add(t_cs_list *list, long item)
{
	char	*mem;

	if (!list)
		return ;
	if (list->capacity - 1 == list->count)
		cs_list_resize(list, list->capacity * 2);
	mem = (char *)list->content;
	ft_memcpy(&(mem[list->count * list->size_of_type]), &item,
		(size_t)list->size_of_type);
	(list->count)++;
}

void	select_item_type(t_cs_list *list, void *item)
{
	if (list->size_of_type == 1)
		cs_list_add(list, (long)(*((char *)item)));
	if (list->size_of_type == 2)
		cs_list_add(list, (long)(*((short int *)item)));
	if (list->size_of_type == 4)
		cs_list_add(list, (long)(*((int *)item)));
	if (list->size_of_type == 8)
		cs_list_add(list, (long)(*((long *)item)));
}

void	cs_list_add_range(t_cs_list *list, int count, void *arr)
{
	int		i;
	int		index;
	char	*s;

	i = 0;
	index = 0;
	s = arr;
	while (i < count)
	{
		select_item_type(list, &(s[index]));
		index += list->size_of_type;
		i++;
	}
}
