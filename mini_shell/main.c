/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:23:51 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/13 20:53:55 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_cmd/builtins.h"
#include "mini_shell.h"

void	clear_read_line(int signo)
{
	(void)signo;
	if (!(g_all.pid_list) || !(g_all.pid_list->count))
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_all.cmd_error_status = 130;
		set_exit_status();
	}
}

char	*get_prompt(void)
{
	char	*tmp;
	char	*prompt;
	char	buf[4097];

	ft_bzero(buf, 4097);
	prompt = getcwd(buf, 4097);
	if (!prompt)
		prompt = get_from_env("PWD", NULL)->content;
	prompt = ft_strrchr(prompt, '/') + 1;
	prompt = my_ft_strjoin("➜ ", prompt);
	tmp = prompt;
	prompt = my_ft_strjoin(prompt, " $>: ");
	ft_free(tmp);
	return (prompt);
}

void	process_line(char **input)
{
	char	*in;
	char	*prompt;

	(void)prompt;
	g_all.i++;
	g_all.current_cmd_file = NULL;
	prompt = get_prompt();
	*input = readline(prompt);
	ft_free(prompt);
	in = ft_strdup(*input);
	ft_free(*input);
	if (is_input_to_skip1(in))
		return ;
	add_new_cmd_history(in, 1);
	if (is_input_to_skip2(in))
		return ;
	process_cmd(in);
	g_all.line_count++;
}

int	main(int argc, char *argv[], char *env[])
{
	char	*input;

	init_g_all(argc, argv, env);
	add_the_past_history();
	signal(SIGINT, clear_read_line);
	signal(SIGQUIT, SIG_IGN);
	augment_shell_level();
	while (1)
		process_line(&input);
	ft_free_all();
	return (g_all.cmd_error_status);
}
