/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:19:10 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 22:37:38 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_cmd.h"

void	print_error_cmd_not_found(char *cmd, t_create_cmd *data, int status)
{
	t_cpp_str	*str;

	if (data->cmd->input_fd == -1 || data->cmd->output_fd == -1)
		return ;
	str = cpp_str_new();
	cpp_str_add(str, "mini-shell: ");
	cpp_str_add(str, cmd);
	cpp_str_add(str, ": ");
	cpp_str_add(str, data->error);
	write(2, str->content, str->count);
	data->cmd_not_found = 1;
	g_all.cmd_error_status = status;
}

int	is_dir(char *cmd)
{
	DIR	*dir;

	dir = opendir(cmd);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

int	get_error_status(char *s)
{
	if (!ft_strncmp(s, "Is a directory\n", 16))
		return (126);
	if (!ft_strncmp(s, "filename argument required\n", 28))
		return (2);
	if (!ft_strncmp(s, "No such file or directory\n", 27))
		return (127);
	if (!ft_strncmp(s, "command not found\n", 19))
		return (127);
	if (!ft_strncmp(s, "Permission denied\n", 19))
		return (126);
	return (127);
}

void	check_path(char *cmd, t_create_cmd *data, int is_path)
{
	data->error = NULL;
	if (cpp_map_get(g_all.builtins, cmd))
		return ;
	if (cmd && is_dir(cmd))
		data->error = "Is a directory\n";
	else if (data->tkn->s[0] == '.' && ft_strlen(data->tkn->s) == 1)
		data->error = "filename argument required\n";
	else if (is_path && access(cmd, F_OK))
		data->error = "No such file or directory\n";
	else if (!cmd || access(cmd, F_OK))
		data->error = "command not found\n";
	else if (!cmd || access(cmd, X_OK))
		data->error = "Permission denied\n";
	if (!g_all.is_error_printed && data->error)
	{
		print_error_cmd_not_found(data->tkn->s, data,
			get_error_status(data->error));
		g_all.is_error_printed = 1;
	}
}
