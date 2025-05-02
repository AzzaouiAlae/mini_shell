/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:36:38 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/02 19:50:04 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HISTORY_H
#define HISTORY_H

#include "../../mini_shell.h"

char	*create_cmd_file(void);
char	*get_cmd_file(int reset, char *file_to_start);

#endif