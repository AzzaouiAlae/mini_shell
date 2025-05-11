/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:01:42 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/11 23:03:18 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_env_vars.h"

void	init_data(t_add_env_var *data, char *kvp)
{
	data->key_len = ft_strlen_delimiter(kvp, "+=");
	data->str_key = cpp_str_new();
	data->str_val = cpp_str_new();
	cpp_str_add_len(data->str_key, kvp, data->key_len);
}
