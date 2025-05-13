/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:09:48 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/13 19:32:42 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cpp_string/cpp_string.h"
#include "get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	char		ch;
	t_cpp_str	*str;
	ssize_t		b;

	str = cpp_str_new();
	cpp_str_add(str, buf);
	while (1)
	{
		b = read(fd, &ch, 1);
		if (b == -1)
			return (NULL);
		if (b > 0)
			cpp_str_add_char(str, ch);
		if (ft_line_verifier(str->content) == 1 || (b != BUFFER_SIZE))
		{
			buf = str->content;
			ft_free(str);
			return (buf);
		}
	}
	return (NULL);
}

char	*ft_saver(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if (((*str)[i] == '\0' && ft_line_verifier((*str)) == 0)
		|| ((*str)[i] != '\0' && (*str)[i + 1] == '\0'))
		return (NULL);
	(*str) = ft_strdup((*str) + (i + 1));
	return ((*str));
}

char	*line_extracter(char *str)
{
	t_gnl	data;

	if (!str || str[0] == '\0')
		return (NULL);
	data.i = 0;
	data.j = 0;
	while (str[data.i] != '\n' && str[data.i] != '\0')
		data.i++;
	data.line = (char *)ft_calloc(1, (size_t)(data.i + 1
				+ (str[data.i] == '\n')));
	if (!data.line)
		return (NULL);
	data.i = 0;
	while (str[data.i] != '\n' && str[data.i] != '\0')
		data.line[data.j++] = str[data.i++];
	if (str[data.i] == '\n')
		data.line[data.j++] = '\n';
	data.line[data.j] = '\0';
	return (data.line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		buf = NULL;
		return (line);
	}
	buf = ft_read(fd, buf);
	if (!buf || buf[0] == '\0')
	{
		buf = NULL;
		return (line);
	}
	line = line_extracter(buf);
	if (!line)
		return (NULL);
	buf = ft_saver(&buf);
	return (line);
}
