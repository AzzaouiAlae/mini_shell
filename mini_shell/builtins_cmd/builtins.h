/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:03 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 03:20:39 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../ft_func/ft_func.h"
# include "../global.h"
# include "../mini_shell.h"

typedef enum e_home_status
{
	e_exist_home = 100,
	e_missing_home = 200,
}			t_home_status;

void		print_export_vars_cmd(t_cmd *cmd);
void		cd(t_cmd *cmd);
void		echo(t_cmd *cmd);
void		env(t_cmd *cmd);
void		exit_cmd(t_cmd *cmd);
void		pwd();
void		unset(t_cmd *cmd);
int			count_args(char **args);
t_cpp_str	*get_from_env(char *var, char *arg);
int			get_stell_home(t_home_status set);
int			print_cd_error(char *arg);
int			check_dash(char *str);
void		print_dash_error(void);
t_cpp_str	*get_path(char *pwd, char *arg);
t_cpp_str	*get_from_env(char *var, char *arg);

#endif