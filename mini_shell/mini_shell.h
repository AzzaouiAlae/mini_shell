/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:44:11 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 21:14:51 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H
# include "alae/env_variable/env_var.h"
# include "cpp_map/cpp_map.h"
# include "ft_func/ft_func.h"
# include "get/get_next_line.h"
# include "global.h"
# include <ctype.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

char	*get_enum_str(int type);
void	print_tokens(void);
void	split_tokens(char *s, char *sep, char *special_sep);
void	init_g_all(int argc, char *argv[], char *env[]);
void	init_env_map(void);
void	get_variables_value(void);
void	process_cmd(char *s);
void	add_vars_to_env(void);
void	rm_single_double_qoute(void);
void	open_redirection_files(void);
void	add_env_var(char *kvp, int type);
void	get_variables_value(void);
void	add_vars_to_env(void);
void	create_cmd(void);
void	set_exit_status(void);
void	execute_cmd(void);
void	init_builtins_map(void);
char	*get_env_vars_heredoc(char *input);
void	check_here_doc(char *input);
void	init_g_all(int argc, char *argv[], char *env_vars[]);
void	set_exit_status(void);
int		is_input_to_skip1(char *input);
int		is_space(char *input);
int		is_input_to_skip2(char *input);
int		ft_check_syntax_error(void);
void	delete_files(int flag);
void	print_redir_error(char *str);
void	add_new_cmd_history(char *input, int new);
void	add_the_past_history(void);
char	*replace_char(char *s, char ch, char ch_to_replace);
char	*my_ft_strjoin(char const *s1, char const *s2);
char	*get_cmd_file(int reset, char *file_to_start);
int		ft_check_syntax_after_pars(void);
void	add_to_env(t_cpp_str *s, char *str_to_change, char *var);
void	add_env(t_key_value *kvp);
void	init_new_env(void);
void	augment_shell_level(void);
void	print_error(char *file_name, int *p_error);

#endif