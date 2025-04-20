#include "ft_func.h"

size_t	ft_strchrlen(const char *s, char ch)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != ch)
		i++;
	return (i);
}

size_t	ft_strstrlen(const char *s, char *sep)
{
	size_t	i;

	i = 0;
	while (s && s[i] && !ft_strchr(sep, s[i]))
		i++;
	return (i);
}
