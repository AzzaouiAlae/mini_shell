/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:42:26 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/21 15:59:01 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HER_DOC_H
#define HER_DOC_H

#include "../../mini_shell.h"


char	*create_file_name(void);
int     here_doc(t_token **tokens, int i);

#endif