/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:44:11 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/04/14 13:16:44 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H
# include "ft_func/ft_func.h"
#include "global.h"
# include <ctype.h>
# include <stdio.h>
# include <string.h>

void split_tokens(char *s, char *sep, char *special_sep);
void init_g_all();

#endif