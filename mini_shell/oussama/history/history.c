/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:44:16 by oel-bann          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/01 09:23:02 by oel-bann         ###   ########.fr       */
=======
/*   Updated: 2025/04/30 07:07:38 by oel-bann         ###   ########.fr       */
>>>>>>> f4bc0d2 (auto commit)
/*                                                                            */
/* ************************************************************************** */


#include "history.h"


void add_the_past_history()
{
    char *file_name, (full_cmd[204800]);
    int fd, (cread);

    file_name = get_cmd_file(1);
    while(file_name)
    {
        fd = open(file_name, O_RDONLY, 0666);
        cread = read(fd,full_cmd,204799);
        full_cmd[cread] = '\0';
        close(fd);
        add_history(full_cmd);
        file_name = get_cmd_file(0);
    }
}

void free_for_new_cmd()
{
    char *before, *(after), (full_cmd[204800]);
    int fd_before, (fd_after) = 0, (cread);
    cread = 0;
    fd_before = 0;
    if (access("/var/tmp/history/cmd_9999.txt", F_OK) == 0)
	{
        before = get_cmd_file(1);
        after = get_cmd_file(0);
        while(after)
        {
            fd_after = open(after, O_RDONLY, 0666);
            cread = read(fd_after,full_cmd,204799);
            full_cmd[cread] = '\0';
            close(fd_after);
            fd_before = open(before, O_RDWR | O_TRUNC, 0666);
            write(fd_before, full_cmd, ft_strlen(full_cmd));
            close(fd_before);
            before = after;
            after = get_cmd_file(0);
        }
        rl_clear_history();
        add_the_past_history();
    }
}

void add_new_cmd_history(char *input, int new)
{
    int fd;
<<<<<<< HEAD
    char *new_input;

    new_input = replace_char(ft_strdup(input), '\n', '\0');
=======

>>>>>>> f4bc0d2 (auto commit)
    free_for_new_cmd();
    if (!g_all.current_cmd_file)
        g_all.current_cmd_file = create_cmd_file();
    if (new == 1)
    {
        fd = open(g_all.current_cmd_file, O_CREAT | O_RDWR, 0666);
<<<<<<< HEAD
        write(fd, new_input, ft_strlen(new_input));
        close(fd);
        add_history(new_input);
=======
        write(fd, input, ft_strlen(input));
        close(fd);
        add_history(input);
>>>>>>> f4bc0d2 (auto commit)
    }
    else
    {
        fd = open(g_all.current_cmd_file, O_RDWR | O_APPEND, 0666);
        write(fd, "\n", 1);
<<<<<<< HEAD
        write(fd, new_input, ft_strlen(new_input));
=======
        write(fd, input, ft_strlen(input));
>>>>>>> f4bc0d2 (auto commit)
        close(fd);
        rl_clear_history();
        add_the_past_history();
    }
}

