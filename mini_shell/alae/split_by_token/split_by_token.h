#ifndef SPLIT_BY_TOKEN_H
# define SPLIT_BY_TOKEN_H
# include "../../cpp_string/cpp_string.h"

typedef struct s_split_data
{
	char	*s;
	char	*sep;
	char	*special_sep;
	char	ch;
	int		i;
	int		first_time;
}			t_split_data;

t_token		*create_token(char *s, int type);
void		add_arg_type(t_split_data *data, int *type);
int			last_cmd_type(void);
int			is_file_name(void);
int			is_arg(t_split_data *data);
int			is_delimiter(t_split_data *data);
int			is_double_quote(t_split_data *data);
void		add_arg_type(t_split_data *data, int *type);
int			is_expand_variable(t_split_data *data);
int			is_pipe(t_split_data *data);
int			is_redirects_heredoc(t_split_data *data);
int			is_redirects_input(t_split_data *data);
int			is_redirects_out_append(t_split_data *data);
int			is_redirects_out_truncate(t_split_data *data);
int			is_single_quote(t_split_data *data);
int			is_cmd_type(void);

#endif