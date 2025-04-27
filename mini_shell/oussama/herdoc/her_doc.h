/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:42:26 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/27 19:41:31 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HER_DOC_H
#define HER_DOC_H

#include "../../mini_shell.h"


typedef struct t_her_doc
{
    char    *limiter;
    char    *str;
    char    *file_name;
    char    *expand_str;
    char    *expand_her;
    int     fd;
} t_her_doc;

char	*create_file_name(void);
int here_doc(t_token **tokens, int i, int expand_her);

#endif