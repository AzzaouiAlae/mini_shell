#ifndef EXECUTE_CMD_H
# define EXECUTE_CMD_H
# include "../../ft_func/ft_func.h"
# include "../../global.h"
# include <sys/wait.h>

typedef struct s_exe_cmd_data
{
	int			i;
	int			c;
	t_cmd		*cmd;
	t_cmd		*old_cmd;
	t_cmd		**cmds;
	t_cs_list	*pid_list;
	void		(*builtin)(t_cmd *c);
}				t_exe_cmd_data;

t_pipe			*create_pipe(void);
void			dup_fd(t_exe_cmd_data *data);
void			close_fd(t_exe_cmd_data *data);
void			close_cmd_pipe(t_exe_cmd_data *data);
void last_arg(int is_child);
void	add_env(t_key_value *kvp);
void init_new_env();

#endif