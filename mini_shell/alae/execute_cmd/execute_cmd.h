/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:53 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/07 21:19:28 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_CMD_H
# define EXECUTE_CMD_H
# include "../../ft_func/ft_func.h"
# include "../../global.h"
# include <sys/wait.h>
#include <signal.h>

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
void			last_arg(int is_child);
void			add_env(t_key_value *kvp);
void			init_new_env(void);
void			create_pipes(t_exe_cmd_data *data);
void	clear_read_line2(int signo);
void	clear_read_line(int signo);

#endif