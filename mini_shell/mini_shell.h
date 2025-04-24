/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:44:11 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/04/24 09:47:38 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H
# include "alae/env_variable/env_var.h"
# include "cpp_map/cpp_map.h"
# include "ft_func/ft_func.h"
# include "global.h"
# include "oussama/check_syntax_error/ft_check_syntax.h"
# include <ctype.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

char				*get_enum_str(int type);
void				print_tokens(void);
void				split_tokens(char *s, char *sep, char *special_sep);
void				init_g_all(int argc, char *argv[], char *env[]);
void				init_env_map(void);
void				get_variables_value(void);
void				process_cmd(char *s);
void				add_vars_to_env(void);
void				rm_single_double_qoute(void);
void				open_redirection_files(void);
void				add_env_var(char *kvp, int type);
void				get_variables_value(void);
void				add_vars_to_env(void);
void				create_cmd(void);
void set_exit_status();

typedef struct s_fd
{
	int				fd;
	int				type;
}					t_fd;

typedef struct s_pipe
{
	int				fd_read;
	int				fd_write;
	struct s_pipe	*next;
}					t_pipe;

typedef struct s_cmd
{
	char			*cmd_path;
	char			**args;
	t_pipe			*pipe;
	int				heredoc_fd;
	int				redir_out_app_fd;
	int				redir_out_trun_fd;
	int				redir_in_fd;
}					t_cmd;

#endif