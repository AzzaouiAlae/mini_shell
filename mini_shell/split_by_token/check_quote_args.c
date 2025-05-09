/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:21:34 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/05/08 11:00:34 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_by_token.h"

int	is_quote_char(t_split_data *data)
{
	if (data->ch)
		return (0);
	if (!ft_strchr("\"'", data->s[data->i]))
		return (0);
	return (1);
}

int	check_quote_in_arg(t_split_data *data)
{
	if (is_quote_char(data))
	{
		data->ch = data->s[data->i];
		if (data->ch == '\'')
			data->type = data->type | e_quote;
		else if (data->ch == '"')
			data->type = data->type | e_double_quote;
		return 1;
	}
	return 0;
}
