/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:42:26 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/12 05:33:24 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HER_DOC_H
# define HER_DOC_H

# include "../get/get_next_line.h"
# include "../mini_shell.h"
# include <signal.h>
# include <sys/wait.h>
//
typedef struct t_her_doc
{
	int		i;
	int		fd;
	int		pid;
	int		status;
	int		expand_her;
	char	*str;
	char	*limiter;
	char	*file_name;
	char	*expand_str;
	t_token	**tokens;
}			t_her_doc;

char		*create_file_name(void);
int			count_here_doc(void);
char		*get_line(char *input, int flag);
void		here_doc(t_token **tokens, int i, int expand_her,
				t_her_doc *her_doc);
void		rem_delimitter_and_heredoc(int i, int fd, char *file_name);
int			create_here_doc_file(t_her_doc *her_doc);
int			create_here_doc_file(t_her_doc *her_doc);
int			is_token(t_her_doc her_doc);
void		exit_her_doc(int signo);
int			is_heredoc_token(t_her_doc her_doc);

#endif