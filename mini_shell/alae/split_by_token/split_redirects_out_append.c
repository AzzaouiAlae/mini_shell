#include "../../mini_shell.h"
#include "split_by_token.h"

int	is_redirects_out_append(t_split_data *data)
{
	if (data->s[data->i] == '>' && data->s[data->i + 1] == '>')
	{
		g_all.token_str = cpp_str_new();
        cpp_str_add(g_all.token_str, ">>");
        g_all.token = create_token(g_all.token_str->content, e_redir_out_app);
		cs_list_add(g_all.tokens, (long)g_all.token);
		data->i += 2;
		return (1);
	}
	return (0);
}
