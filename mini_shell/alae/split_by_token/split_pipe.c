#include "../../mini_shell.h"
#include "split_by_token.h"

int	is_pipe(t_split_data *data)
{
	if (data->s[data->i] == '|')
	{
		g_all.token_str = cpp_str_new();
		cpp_str_add(g_all.token_str, "|");
        g_all.token = create_token(g_all.token_str->content, e_pipe);
		cs_list_add(g_all.tokens, (long)g_all.token);
        data->i++;
        return 1;
	}
	return (0);
}
