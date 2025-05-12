/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:50 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/12 11:57:33 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmd.h"

int	use_fork(t_exe_cmd_data *data)
{
	if (g_all.cmds->count != 1)
		return (1);
	if (!data->cmd->cmd_path)
		return (0);
	if (data->cmd->input_fd == -1 || data->cmd->output_fd == -1)
		return (0);
	if (!ft_strncmp(data->cmd->cmd_path, "export", 7)
		&& ft_strslen(data->cmd->args) > 1)
		return (0);
	if (!ft_strncmp(data->cmd->cmd_path, "unset", 6))
		return (0);
	if (!ft_strncmp(data->cmd->cmd_path, "cd", 3))
		return (0);
	if (!ft_strncmp(data->cmd->cmd_path, "exit", 5))
		return (0);
	return (1);
}

void	run(t_exe_cmd_data *data)
{
	if (use_fork(data) && data->cmds[0] == data->cmd
		&& !ft_strncmp(data->cmd->cmd_path, "env", 4))
	{
		init_new_env();
		last_arg(1);
		cpp_map_foreach(g_all.custom_env, add_env);
	}
	if (data->cmd->cmd_path && use_fork(data))
		dup_fd(data);
	data->builtin = cpp_map_get(g_all.builtins, data->cmd->cmd_path);
	if (data->builtin && data->cmd->input_fd != -1
		&& data->cmd->output_fd != -1)
		data->builtin(data->cmd);
	else if (data->cmd->cmd_path)
	{
		if (data->cmd->input_fd != -1 && data->cmd->output_fd != -1)
		{
			execve(data->cmd->cmd_path, data->cmd->args,
				(char **)(g_all.new_env->content));
			ft_exit(errno);
		}
	}
	if (use_fork(data))
		ft_exit(g_all.cmd_error_status);
}

void	run_cmds(t_exe_cmd_data *data)
{
	t_cpp_str	*s_err;

	g_all.current_pid = 0;
	if (data->cmd->pipe && data->cmd->pipe->bad_fd)
	{
		s_err = cpp_str_new();
		cpp_str_add(s_err, data->cmd->args[0]);
		cpp_str_add(s_err, ": write error: Bad file descriptor\n");
		write(2, s_err->content, s_err->count);
		return ;
	}
	if (use_fork(data))
	{
		g_all.current_pid = fork();
		if (!g_all.current_pid)
			signal(SIGQUIT, SIG_DFL);
	}
	if (g_all.current_pid)
		cs_list_add(data->pid_list, g_all.current_pid);
	else
		run(data);
}

void	wait_cmds(t_exe_cmd_data *data)
{
	data->j = 0;
	data->status = 0;
	data->print_nl = 1;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, sig_quit);
	while (data->pid_list->count)
	{
		data->pids = data->pid_list->content;
		waitpid(data->pids[0], &(data->status), 0);
		if (data->status == 2 && data->print_nl)
		{
			write(1, "\n", 1);
			g_all.cmd_error_status = 130;
			data->print_nl = 0;
		}
		cs_list_delete(data->pid_list, 0);
		data->j++;
	}
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, clear_read_line);
	if (data->j && !g_all.ctrl_c)
		g_all.cmd_error_status = 0;
	if (data->j && WIFEXITED(data->status) && !g_all.ctrl_c)
		g_all.cmd_error_status = WEXITSTATUS(data->status);
}

void	execute_cmd(void)
{
	t_exe_cmd_data	data;

	if (!g_all.cmds || !g_all.cmds->count)
		return ;
	ft_bzero(&data, sizeof(t_exe_cmd_data));
	data.cmds = g_all.cmds->content;
	data.c = g_all.cmds->count;
	data.cmd = data.cmds[data.i];
	if (!g_all.pid_list)
		g_all.pid_list = cs_list_new(sizeof(int));
	data.pid_list = g_all.pid_list;
	g_all.ctrl_c = 0;
	while (data.c > data.i)
	{
		data.cmd = data.cmds[data.i];
		create_pipes(&data);
		run_cmds(&data);
		data.i++;
	}
	write(g_all.terminal_fd, "close in parent\n", 16);
	close_fd(&data);
	wait_cmds(&data);
}
