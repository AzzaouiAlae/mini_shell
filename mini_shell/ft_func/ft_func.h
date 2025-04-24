#ifndef FT_FUNC_H
# define FT_FUNC_H
# include "../cpp_map/cpp_map.h"
# include "../cpp_string/cpp_string.h"
# include "../garbage_collector/garbage_collector.h"
# include <stdlib.h>

char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strnstr(char *haystack, char *needle, size_t len);
char		**ft_super_split(const char *s, char *sep, char *special_sep);
char		*ft_strldup(const char *s1, size_t len);
size_t		ft_strchrlen(const char *s, char ch);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlen_delimiter(const char *s, char *sep);
char		*str_find_char(const char *s, char *sep);
t_cpp_str	*ft_itoa(int num);
int			ft_strncmp(char *s1, char *s2, int n);

#endif