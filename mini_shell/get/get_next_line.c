/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:09:48 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/01 06:54:19 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	char	*stored_buffer;
	char	*tmp;
	ssize_t	b;

	while (1)
	{
		tmp = (char *)malloc((size_t)(BUFFER_SIZE) + 1);
		if (!tmp)
			return (free(buf), NULL);
		b = read(fd, tmp, BUFFER_SIZE);
		if (b == -1)
			return (free(tmp), free(buf), NULL);
		tmp[b] = '\0';
		stored_buffer = buf;
		buf = my_ft_strjoin(buf, tmp);
		if (!buf)
			return (NULL);
		if (stored_buffer)
			free(stored_buffer);
		if (tmp)
			free(tmp);
		if (ft_line_verifier(buf) == 1 || (b != BUFFER_SIZE))
			return (buf);
	}
	return (NULL);
}

char	*ft_saver(char **str)
{
	char	*tmp;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if (((*str)[i] == '\0' && ft_line_verifier((*str)) == 0)
		|| ((*str)[i] != '\0' && (*str)[i + 1] == '\0'))
	{
		free((*str));
		return (NULL);
	}
	else
	{
		tmp = (*str);
		(*str) = ft_strdup((*str) + (i + 1));
		free(tmp);
	}
	return ((*str));
}

char	*line_extracter(char *str)
{
	char	*line;

	int i, (j);
	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc((size_t)(i + 1 + (str[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		line[j++] = str[i++];
	if (str[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		buf = NULL;
		return (line);
	}
	buf = ft_read(fd, buf);
	if (!buf || buf[0] == '\0')
	{
		free(buf);
		buf = NULL;
		return (line);
	}
	line = line_extracter(buf);
	if (!line)
		return (free(buf), NULL);
	buf = ft_saver(&buf);
	return (line);
}

// int main()
// {
//     int fd = open("file.txt",O_RDWR);
//     char * str = NULL;
//     // int i = 0;

//         str = get_next_line(fd);
//         printf("[%s]",str);
//         free(str);

//     close(fd);
// }
