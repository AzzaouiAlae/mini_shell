/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:29 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 12:14:59 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	pwd(t_cmd *cmd)
{
	char	buf[4097];
	char	*cwd;

	(void)cmd;
	ft_bzero(buf, 4097);
	cwd = get_from_env("PWD", NULL)->content;
	if (!cwd)
	{
		cwd = getcwd(buf, 4097);
		if (!cwd)
			return ;
	}
	printf("%s\n", cwd);
}
