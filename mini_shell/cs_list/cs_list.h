/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:44:24 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/29 13:16:19 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CS_LIST_H
# define CS_LIST_H
# include "../garbage_collector/garbage_collector.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_cs_list
{
	void	*content;
	int		size_of_type;
	int		count;
	int		capacity;
	int		type;
}			t_cs_list;

void		cs_list_add(t_cs_list *list, long item);
void		cs_list_add_range(t_cs_list *list, int count, void *arr);
t_cs_list	*cs_list_new(int size_of_type);
t_cs_list	*cs_list_new_capacity(int size_of_type, int capacity);
void		cs_list_resize(t_cs_list *list, int capacity);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		cs_list_delete(t_cs_list *list, int index);
void		cs_list_inset_at(t_cs_list *list, int index, long item);
int			cs_list_contains(t_cs_list *list, long item);
void		cs_list_clear(t_cs_list *list);

#endif