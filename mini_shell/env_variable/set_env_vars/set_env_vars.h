/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_vars.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:20:18 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 23:03:14 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ENV_VARS_H
# define SET_ENV_VARS_H
# include "../../ft_func/ft_func.h"
# include "../../split_by_token/split_by_token.h"
# include "../env_var.h"

typedef struct s_set_env_vars
{
	int			i;
	int			j;
	int			type;
	int			count;
	int			has_cmd;
	int			is_export_args;
	char		**args;
	t_token		**tokens;
}				t_set_env_vars;

typedef struct s_add_env_var
{
	t_cpp_str	*str_key;
	t_cpp_str	*str_val;
	t_cs_list	*val_list;
	t_cs_list	*val;
	int			val_len;
	int			key_len;
	char		*s;
}				t_add_env_var;

int				delete_export_token(t_set_env_vars *data);
int				is_env_var(t_set_env_vars *data);
int				is_tokens_has_cmd(void);
int				is_path(char *s);
void			add_export_var(char *kvp, t_var_type type);
void			init_data(t_add_env_var *data, char *kvp);

#endif