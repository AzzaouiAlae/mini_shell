#ifndef FT_FUNC_H
# define FT_FUNC_H
# include <stdlib.h>
#include "../garbage_collector/garbage_collector.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int     ft_strcmp(char *s1, char *s2);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	**ft_super_split(const char *s, char *sep, char *special_sep);
char	*ft_strldup(const char *s1, size_t len);
size_t	ft_strchrlen(const char *s, char ch);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strcmp2(char *s1, char *s2);
size_t	ft_strstrlen(const char *s, char *sep);
char	*ft_strstrchr(const char *s, char *sep);

#endif