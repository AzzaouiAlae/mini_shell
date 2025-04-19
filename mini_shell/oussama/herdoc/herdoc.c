/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:16:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/18 22:40:12 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

void	ft_limiter_rem(int i, char *filename)
{
	cs_list_delete(g_all.tokens, i);
    cs_list_delete(g_all.tokens, i - 1);
    cs_list_inset_at(g_all.tokens, i - 1, (long)filename);
}

int	here_doc(t_token **tokens, int i)
{
	int (fd);
	char *(limiter), *(str), *(file_name);
	file_name = create_file_name();
	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd == -1)
		return (perror("ERROR HERDOC FILE"), ft_exit(127), 0);
	str = readline(">");
	limiter = ft_strjoin(tokens[i]->s, "\n");
	while (ft_strncmp(limiter, str, ft_strlen(limiter)) != 0
		|| ft_strncmp(limiter, str, ft_strlen(limiter) - 1) != 0)
	{
        if (!str)
        {
			printf("warning: here-document at line %d ", g_all.line_count);
            printf("delimited by end-of-file (wanted `%s')", limiter);
            ft_exit(0);
        }
		write(fd, str, ft_strlen(str));
		free(str);
		str = readline(">");;
	}
	free(str);
	ft_limiter_rem(i, file_name);
	return (0);
}
