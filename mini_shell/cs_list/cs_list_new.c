/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_list_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:44:11 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/28 19:18:17 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs_list.h"

t_cs_list	*cs_list_new(int size_of_type)
{
	t_cs_list	*list;

	list = ft_calloc(1, sizeof(t_cs_list));
	list->content = ft_calloc(size_of_type, 32);
	list->size_of_type = size_of_type;
	list->count = 0;
	list->capacity = 32;
	list->free_content = 1;
	return (list);
}

t_cs_list	*cs_list_new_free_contante(int size_of_type, int free_cont)
{
	t_cs_list	*list;

	list = ft_calloc(1, sizeof(t_cs_list));
	if (free_cont)
		list->content = ft_calloc(size_of_type, 4);
	else
		list->content = ft_calloc_without_save(size_of_type, 4);
	list->size_of_type = size_of_type;
	list->count = 0;
	list->capacity = 4;
	list->free_content = free_cont;
	return (list);
}

t_cs_list	*cs_list_new_capacity(int size_of_type, int capacity)
{
	t_cs_list	*list;

	list = ft_calloc(1, sizeof(t_cs_list));
	list->content = ft_calloc(size_of_type, capacity);
	list->size_of_type = size_of_type;
	list->count = 0;
	list->capacity = capacity;
	list->free_content = 1;
	return (list);
}
