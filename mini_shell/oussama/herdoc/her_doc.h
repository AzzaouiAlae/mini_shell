/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:42:26 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/27 17:05:00 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HER_DOC_H
#define HER_DOC_H

#include "../../mini_shell.h"


typedef
char	*create_file_name(void);
char *here_doc(t_token **tokens, int i, int expand_her);

#endif