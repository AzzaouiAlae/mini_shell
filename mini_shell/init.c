/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:23:45 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 11:01:34 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_cmd/builtins.h"
#include "mini_shell.h"

t_global	g_all;

void	init_g_all(int argc, char *argv[], char *env_vars[])
{
	t_cs_list	*paths;

	ft_bzero(&g_all, sizeof(t_global));
	g_all.env = env_vars;
	g_all.argc = argc;
	g_all.argv = argv;
	init_env_map();
	init_builtins_map();
	g_all.ch_i = cs_list_new(sizeof(int));
	g_all.files_to_remove = cs_list_new(sizeof(char *));
	g_all.variables_name = cs_list_new(sizeof(char *));
	paths = cpp_map_get(g_all.custom_env, "PATH");
	if (!paths)
	{
		paths = cs_list_new(sizeof(char));
		cs_list_add_range(paths, 60,
			"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
		cpp_map_add(g_all.custom_env, "PATH", paths);
	}
}

void	set_exit_status(void)
{
	t_cs_list	*str;
	t_cpp_str	*exit_str;

	str = cs_list_new(sizeof(char));
	exit_str = ft_itoa(g_all.cmd_error_status);
	cs_list_add_range(str, exit_str->count, exit_str->content);
	cpp_map_add(g_all.custom_env, "?", str);
}

void	init_new_env(void)
{
	if (!g_all.new_env)
		g_all.new_env = cs_list_new(sizeof(char *));
	else
		cs_list_clear(g_all.new_env);
}
