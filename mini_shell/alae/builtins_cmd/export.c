#include "builtins.h"

void	print_env_var(t_key_value *kvp)
{
	t_cs_list	*value;

	value = kvp->value;
	if (value->type)
		printf("%s=%s\n", kvp->key, value->content);
}

void	print_env_vars(void)
{
	cpp_map_foreach(g_all.custom_env, print_env_var);
}

void	print_export_vars_cmd(t_cmd *cmd)
{
	int	fd;
	int	old_fd;

	if (ft_strslen(cmd->args) > 1)
		return ;
	fd = 1;
	if (cmd && cmd->redir_out_app_fd)
		fd = cmd->redir_out_app_fd;
	if (cmd && cmd->redir_out_trun_fd)
		fd = cmd->redir_out_trun_fd;
	if (cmd && cmd->pipe)
		fd = cmd->pipe->fd_write;
	g_all.current_cmd = cmd;
	old_fd = dup(1);
	dup2(fd, 1);
	cpp_map_foreach(g_all.custom_env, print_env_var);
	dup2(old_fd, 1);
}
