#ifndef SPLIT_BY_TOKEN_H
# define SPLIT_BY_TOKEN_H
# include "../../cpp_string/cpp_string.h"
# include "../../global.h"
# include "../../mini_shell.h"

typedef struct s_split_data
{
	char	*s;
	char	*sep;
	char	*special_sep;
	char	ch;
	int		i;
	int		first_time;
	int		type;
}			t_split_data;

t_token		*create_token(char *s, int type);
int			last_cmd_type(void);
int			is_file_name(void);
int			is_arg(t_split_data *data);
int			is_delimiter(t_split_data *data);
int			is_double_quote(t_split_data *data);
void		add_arg_type(t_split_data *data);
int			is_expand_variable(t_split_data *data);
int			is_pipe(t_split_data *data);
int			is_redirects_heredoc(t_split_data *data);
int			is_redirects_input(t_split_data *data);
int			is_redirects_out_append(t_split_data *data);
int			is_redirects_out_truncate(t_split_data *data);
int			is_single_quote(t_split_data *data);
int			is_cmd_type(void);
int			check_dollar_ch_arg(t_split_data *data);
int			check_export_cmd(t_split_data *data, char *export);
int			is_dollar_char(t_split_data *data);
int			is_var_to_get(t_split_data *data);
int			is_dollar_to_skip(t_split_data *data);
int			check_quote_in_arg(t_split_data *data);
void		add_token(t_split_data *data);
int			is_var_to_set(t_split_data *data);
int is_valid_var_name(char *str);
int is_valid_var_name_char(char ch);
int is_digit(char ch);

#endif