/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:23:51 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 17:59:09 by aazzaoui         ###   ########.fr       */
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
	char	*prompt;
	char	buf[4097];

	ft_bzero(buf, 4097);
	prompt = getcwd(buf, 4097);
	if (!prompt)
	{
		prompt = get_from_env("PWD", NULL)->content;
	}
	prompt = ft_strrchr(prompt, '/') + 1;
	prompt = my_ft_strjoin("➜ ", prompt);
	prompt = my_ft_strjoin(prompt, " $>: ");
	return (prompt);
}

char	*read_input(void)
{
	char	*line;

	if (isatty(fileno(stdin)))
	{
		return (readline(get_prompt()));
	}
	else
	{
		line = get_next_line(0);
		if (ft_strlen(line))
			line[ft_strlen(line) - 1] = '\0';
		return (line);
	}
}

void	process_line(char **input)
{
	g_all.i++;
	g_all.current_cmd_file = NULL;
	//*input = readline(get_prompt());
	*input = read_input();
	if (is_input_to_skip1(*input))
		return ;
	add_new_cmd_history(*input, 1);
	if (is_input_to_skip2(*input))
		return ;
	process_cmd(*input);
	ft_free(*input);
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
	ft_free(input);
	ft_free_all();
	return (g_all.cmd_error_status);
}
