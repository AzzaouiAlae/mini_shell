/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:36:38 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/29 11:22:22 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HISTORY_H
#define HISTORY_H

#include "../../mini_shell.h"

char	*create_cmd_file(void);
char	*get_cmd_file(int reset);

#endif