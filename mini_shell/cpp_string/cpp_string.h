#ifndef CPP_STRING_H
# define CPP_STRING_H
# include "../garbage_collector/garbage_collector.h"

typedef struct s_cpp_str
{
	char	*content;
	int		count;
	int		capacity;
}			t_cpp_str;

void		cpp_str_resize(t_cpp_str *str, int capacity);
void		cpp_str_delete_char(t_cpp_str *str, int index);
void		cpp_str_delete_len(t_cpp_str *str, int index, int len);
void		cpp_str_insert(t_cpp_str *str, char *value, int index);
void		cpp_str_insert_char(t_cpp_str *str, char value, int index);
void		cpp_str_add_len(t_cpp_str *str, char *arr, int len);
void		cpp_str_add(t_cpp_str *str, char *arr);
void		cpp_str_add_char(t_cpp_str *str, char ch);
t_cpp_str	*cpp_str_new_capacity(int capacity);
t_cpp_str	*cpp_str_new(void);
void	cpp_str_delete_char(t_cpp_str *str, int index);
t_cpp_str	*cpp_str_new_substitute(char *s);
void cpp_str_clear(t_cpp_str *str);

#endif