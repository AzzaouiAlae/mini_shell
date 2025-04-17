#ifndef GLOBAL_H
#define GLOBAL_H
# include "cs_list/cs_list.h"

typedef enum e_token_type
{
	e_none = 0,
	e_args = 1,
	e_pipe = 2,
	e_heredoc = 4,
	e_redir_out_app = 8,
	e_redir_out_trun = 16,
	e_redir_in = 32,
	e_var_to_get = 64,
	e_quote = 128,
	e_double_quote = 256,
	e_file_name = 512,
	e_cmd = 1024,
	e_path = 2048,
	e_set_var = 4096,
	e_var_to_set = 8192,
	e_delimiter = 16384,
	e_error_status = 32768,
}				t_token_type;

typedef struct s_token
{
	char		*s;
	int			type;
}				t_token;

typedef struct s_globale
{
    t_cs_list	*tokens;
    t_cs_list	*token_str;
	t_token		*token;
	int cmd_error_status;
	t_token_type	last_cmd_type;
} t_global;

extern t_global g_all;

#endif