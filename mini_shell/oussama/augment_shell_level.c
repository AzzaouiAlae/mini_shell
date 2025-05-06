#include "../mini_shell.h"

void	augment_shell_level(void)
{
	t_cpp_str	*str;
	t_cs_list	*value;
	int			shlvl;
	int			error;
	char		*buf;

	shlvl = 0;
	error = 0;
	str = cpp_str_new();
	buf = ft_calloc(1, 4097);
	value = cpp_map_get(g_all.custom_env, "SHLVL");
	if (!value)
	{
		add_to_env(NULL, getcwd(buf, 4097), "PWD");
		cpp_str_add(str, ft_strdup("0"));
		value = cs_list_new(sizeof(char));
		cs_list_add(value, (long)(str->content));
	}
	shlvl = ft_atoi(value->content, &error) + 1;
	cpp_str_clear(str);
	cpp_str_add(str, ft_itoa(shlvl)->content);
	add_to_env(str, NULL, "SHLVL");
}
