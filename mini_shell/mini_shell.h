/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:44:11 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/04/18 11:03:33 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H
# include "ft_func/ft_func.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "oussama/check_syntax_error/ft_check_syntax.h"
#include "global.h"
# include <ctype.h>
# include <stdio.h>
# include <string.h>

char *get_enum_str(int type);
void print_tokens(char *s);
void split_tokens(char *s, char *sep, char *special_sep);
void init_g_all();
#endif