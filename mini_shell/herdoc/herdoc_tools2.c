/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 05:32:49 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 05:33:09 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

int	is_heredoc_token(t_her_doc her_doc)
{
	if (!(her_doc.tokens[her_doc.i + 1]))
		return (0);
	if (!(her_doc.tokens[her_doc.i]->type & e_heredoc))
		return (0);
	if (!(her_doc.tokens[her_doc.i + 1]->type & e_delimiter))
		return (0);
	return (1);
}
