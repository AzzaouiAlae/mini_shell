/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:23:48 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:23:49 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	is_input_to_skip1(char *input)
{
	if (!input)
		ft_exit(g_all.cmd_error_status);
	if (!(*input))
		return (1);
	if (!ft_strcmp(input, "\n"))
	{
		free(input);
		printf("\n");
		return (1);
	}
	return (0);
}

int	is_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	is_input_to_skip2(char *input)
{
	if (is_space(input))
		return (1);
	if (ft_strlen(input) == 1 && str_find_char(input, ":!#"))
	{
		if (str_find_char(input, "!"))
		{
			g_all.cmd_error_status = 1;
			set_exit_status();
		}
		return (1);
	}
	return (0);
}
