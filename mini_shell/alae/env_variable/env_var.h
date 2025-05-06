/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:23 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/06 22:20:26 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H
# include "../../ft_func/ft_func.h"
# include "../../mini_shell.h"
# include "../split_by_token/split_by_token.h"

typedef enum e_var_type
{
	e_local_var,
	e_global_var
}		t_var_type;

char	**split_var_token(t_cpp_str *str_token);
void	print_env_vars(void);

#endif