#include "cpp_string.h"

void	cpp_str_add_char(t_cpp_str *str, char ch)
{
	if (!str)
		return ;
	if (str->capacity - 1 == str->count)
		cpp_str_resize(str, str->capacity * 2);
	str->content[str->count] = ch;
	(str->count)++;
}

void	cpp_str_add(t_cpp_str *str, char *arr)
{
	int	i;

	if (!str || !arr || !arr[0])
		return ;
	i = 0;
	while (arr[i])
	{
		cpp_str_add_char(str, arr[i]);
		i++;
	}
}

void	cpp_str_add_len(t_cpp_str *str, char *arr, int len)
{
	int i;

	if (!str || !arr || !arr[0])
		return ;
	i = 0;
	while (arr[i] && len > i)
	{
		cpp_str_add_char(str, arr[i]);
		i++;
	}
}
