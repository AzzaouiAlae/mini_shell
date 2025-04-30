#include "builtins.h"

void	print_env_var(t_key_value *kvp)
{
	t_cs_list	*value;

	value = kvp->value;
	if (value->type)
		printf("declare -x %s=\"%s\"\n", kvp->key, value->content);
}

void	print_env_vars(void)
{
	cpp_map_foreach(g_all.custom_env, print_env_var);
}

void	print_export_vars_cmd(t_cmd *cmd)
{
	int i;
	int	fd;
	int	old_fd;

	i = 0;
	if (cmd && cmd->pipe)
	{
		fd = cmd->pipe->fd_write;
		dup2(fd, 1);
	}
	g_all.current_cmd = cmd;
	if (cmd && cmd->output_fd)
		dup2(cmd->output_fd, 1);
	if(cmd->args[1])
		return ;
	cpp_map_foreach(g_all.custom_env, print_env_var);
}
