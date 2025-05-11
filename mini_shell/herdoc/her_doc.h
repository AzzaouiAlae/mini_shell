/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:42:26 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/11 05:08:01 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HER_DOC_H
# define HER_DOC_H

# include "../get/get_next_line.h"
# include "../mini_shell.h"
# include <sys/wait.h>
# include <signal.h>

typedef struct t_her_doc
{
	char	*limiter;
	char	*str;
	char	*file_name;
	char	*expand_str;
	int		expand_her;
	int		fd;
}			t_her_doc;

char	*create_file_name(void);
int		count_here_doc(void);
char	*get_line(char *input, int flag);
void	here_doc(t_token **tokens, int i, int expand_her, t_her_doc *her_doc);
void	rem_delimitter_and_heredoc(int i, int fd, char *file_name);
int		create_here_doc_file(t_her_doc *her_doc);

#endif