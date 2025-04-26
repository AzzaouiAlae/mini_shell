/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:16:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/25 04:37:45 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

char *here_doc(char *delimiter, int i)
{
	static 
	int (fd);
	char *(limiter), *(str), *(file_name);
	file_name = create_file_name();
	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd == -1)
		return (perror("ERROR HERDOC FILE"), ft_exit(127), NULL);
	str = readline("$>: ");
	limiter = ft_strjoin(delimiter, "\n");
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
		str = readline("$>: ");;
	}
	free(str);
	return (file_name);
}


int main()
{
	
}