#include "cpp_string.h"
#include "../ft_func/ft_func.h"

t_cpp_str	*cpp_str_new(void)
{
	t_cpp_str	*str;

	str = ft_calloc(1, sizeof(t_cpp_str));
	str->content = ft_calloc(16, sizeof(char));
	str->count = 0;
	str->capacity = 16;
	return (str);
}

t_cpp_str	*cpp_str_new_capacity(int capacity)
{
	t_cpp_str	*str;

	str = ft_calloc(1, sizeof(t_cpp_str));
	str->content = ft_calloc(capacity + 1, sizeof(char));
	str->count = 0;
	str->capacity = capacity + 1;
	return (str);
}

t_cpp_str	*cpp_str_new_substitute(char *s)
{
	t_cpp_str	*str;

	str = ft_calloc(1, sizeof(t_cpp_str));
	str->content = s;
	str->capacity = ft_strlen(s) + 1;
	str->count = str->capacity - 1;
	return (str);
}