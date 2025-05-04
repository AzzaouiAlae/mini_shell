/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:36:00 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/04 05:00:17 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int count_args(char **args)
{
    int i;

    i = 0;
    if (!args)
        return(0);
    while(args[i])
        i++;
    return(i);
}

int get_stell_home (t_home_status set)
{
    static int home;

    if (set == e_exist_home)
        home = 1;
    else if (set == e_missing_home)
        home = 0;
    return (home);
    
}

int print_cd_error(char *arg)
{
    if (get_stell_home(0) == 1)
    {
        g_all.cmd_error_status = 1;
        perror(my_ft_strjoin("Minishell cd: ", arg));
    }
    else
        write(2, "Minishell: cd: HOME not set\n", 28);
    return 1;
}