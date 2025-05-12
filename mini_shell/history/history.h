/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:36:38 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 09:27:06 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "../mini_shell.h"
/*
char		full_cmd[204800];

	char *before, *(after);
	int fd_before, (fd_after) = 0, (cread);
*/
typedef struct s_history_data
{
	int		cread;
	int		fd_before;
	int		fd_after;
	char	*before;
	char	*after;
	char	full_cmd[204800];
}			t_history_data;

char		*create_cmd_file(void);
char		*get_cmd_file(int reset, char *file_to_start);

#endif