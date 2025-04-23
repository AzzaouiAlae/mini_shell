#ifndef CREATE_CMD_D
# define CREATE_CMD_D
# include "../../mini_shell.h"

typedef struct s_create_cmd
{
	int			i;
	int			res_fd;
	int			fd;
	char		*cmd_path;
	t_token		*tkn;
	t_token		**tkns;
	t_cmd		*cmd;
	t_cs_list	*cmd_args;
}				t_create_cmd;

#endif