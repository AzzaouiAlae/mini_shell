/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:23:37 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:53:06 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

char	*replace_char(char *s, char ch, char ch_to_replace)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == ch)
			s[i] = ch_to_replace;
		i++;
	}
	return (s);
}
