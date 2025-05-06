/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:18:29 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:18:30 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	pwd(t_cmd *cmd)
{
	char	buf[4097];
	char	*cwd;

	ft_bzero(buf, 4097);
	cwd = getcwd(buf, 4097);
	if (!cwd)
	{
		printf("%s\n", get_from_env("PWD", NULL)->content);
		return ;
	}
	printf("%s\n", cwd);
}
