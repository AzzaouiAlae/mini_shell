#ifndef CREATE_CMD_D
# define CREATE_CMD_D
# include "../../mini_shell.h"
# include "../env_variable/set_env_vars/set_env_vars.h"
# include <dirent.h>

typedef struct s_create_cmd
{
	int			i;
	int			fd;
	int			res_fd;
	int			cmd_not_found;
	char		*cmd_path;
	char		*error;
	t_token		**tkns;
	t_token		*tkn;
	t_cmd		*cmd;
	t_cs_list	*cmd_args;
}				t_create_cmd;

void			print_error_cmd_not_found(char *cmd, t_create_cmd *data,
					int status);
int				check_path(char *cmd, t_create_cmd *data);
int				is_dir(char *cmd);

#endif