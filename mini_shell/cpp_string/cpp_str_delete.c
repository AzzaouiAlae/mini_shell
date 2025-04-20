#include "cpp_string.h"

void	cpp_delete_char(t_cpp_str *str, int index)
{
	if (!str || index > str->count - 1)
		return ;
	while (index < str->count - 1)
	{
		str->content[index] = str->content[index + 1];
		index++;
	}
	if (index == str->count - 1)
		str->content[index] = 0;
	str->count--;
}

void	cpp_str_delete_len(t_cpp_str *str, int index, int len)
{
	int	ln;
	int	i;

	if (index > str->count - 1 || index < 0 || len < 0 || !str)
		return ;
	ln = (str->count - 1) - (index + len);
	if (ln < 0)
		ln = str->count - index;
	if (ln < len)
		len = ln;
	while (str->count > index)
	{
		str->content[index] = str->content[index + len];
		index++;
	}
	str->count -= len;
}
