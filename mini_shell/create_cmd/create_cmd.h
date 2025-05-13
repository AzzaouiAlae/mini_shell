/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:19:00 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/13 20:41:53 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_CMD_H
# define CREATE_CMD_H
# include "../env_variable/set_env_vars/set_env_vars.h"
# include "../mini_shell.h"
# include <dirent.h>

typedef struct s_create_cmd
{
	int			i;
	int			fd;
	int			res_fd;
	int			cmd_not_found;
	char		*cmd_path;
	char		*error;
	char		**paths;
	t_token		**tkns;
	t_token		*tkn;
	t_cmd		*cmd;
	t_cs_list	*cmd_args;
}				t_create_cmd;

void			print_error_cmd_not_found(char *cmd, t_create_cmd *data,
					int status);
void			check_path(char *cmd, t_create_cmd *data, int is_path);
int				is_dir(char *cmd);
int				check_builtins_cmd(t_create_cmd *data);
void			run_builtin_cmds(t_create_cmd *data);
char			*get_cmd_path(char *cmd_s, t_create_cmd *data);
int				get_error_status(char *s);
void			add_input_fd(t_create_cmd *data);
void			add_output_fd(t_create_cmd *data);
void			add_fd_to_cmd(t_create_cmd *data);
void			free_path(t_create_cmd *data);

#endif