/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:57:14 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/12 11:50:50 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "cpp_map/cpp_map.h"
# include "cpp_string/cpp_string.h"
# include "cs_list/cs_list.h"

typedef enum e_token_type
{
	e_none = 0,
	e_args = 1,
	e_pipe = 2,
	e_heredoc = 4,
	e_redir_out_app = 8,
	e_redir_out_trun = 16,
	e_redir_in = 32,
	e_var_to_get = 64,
	e_quote = 128,
	e_double_quote = 256,
	e_file_name = 512,
	e_cmd = 1024,
	e_path = 2048,
	e_set_var = 4096,
	e_var_to_set = 8192,
	e_delimiter = 16384,
	e_heredoc_fd = 32768,
	e_redir_out_app_fd = 65536,
	e_redir_out_trun_fd = 131072,
	e_redir_in_fd = 262144,
}					t_token_type;

typedef struct s_token
{
	char			*s;
	int				type;
}					t_token;

typedef struct s_pipe
{
	int				bad_fd;
	int				fd_read;
	int				fd_write;
	struct s_pipe	*next;
}					t_pipe;

typedef struct s_cmd
{
	char			*cmd_path;
	char			**args;
	t_pipe			*pipe;
	int				output_fd;
	int				input_fd;
}					t_cmd;

typedef struct s_globale
{
	int				i;
	int				terminal_fd;
	int				argc;
	int				error_i;
	int				current_pid;
	int				line_count;
	int				is_error_printed;
	int				cmd_error_status;
	int				ctrl_c;
	t_token_type	last_cmd_type;
	char			*current_cmd_file;
	char			**env;
	char			**argv;
	t_token			*token;
	t_cpp_str		*token_str;
	t_cpp_map		*custom_env;
	t_cs_list		*tokens;
	t_cs_list		*cmds;
	t_cmd			*current_cmd;
	t_cpp_map		*builtins;
	t_cs_list		*files_to_remove;
	t_pipe			*pipes;
	t_cs_list		*new_env;
	t_cs_list		*ch_i;
	t_cs_list		*variables_name;
	t_cs_list		*pid_list;
}					t_global;

extern t_global		g_all;

#endif