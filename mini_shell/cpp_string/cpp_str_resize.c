#include "cpp_string.h"

void	cpp_str_resize(t_cpp_str *str, int capacity)
{
	int		i;
	char	*s;
	char	*tmp;

	i = 0;
	s = ft_calloc(sizeof(char), capacity);
	while (i < str->count)
	{
		s[i] = str->content[i];
		i++;
	}
	tmp = str->content;
	str->content = s;
	str->capacity = capacity;
	ft_free(tmp);
}
