/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_after_pars.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:17:25 by oel-bann          #+#    #+#             */
/*   Updated: 2025/05/08 05:35:16 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	print_ambiguous_error(char *str)
{
	write(2, "Minishell : ", 12);
	write(2, str, ft_strlen(str));
	write(2, ": ambiguous redirect\n", 21);
	g_all.cmd_error_status = 1;
}

int	check_redir_double_file(t_token **token, int i, int *index)
{
	char	**var_names;
	char	*var_name;
	int		after_cmd;

	var_names = g_all.variables_name->content;
	var_name = var_names[*index];
	after_cmd = token[i + 1] && token[i + 2] && e_file_name & token[i + 1]->type
		&& e_file_name & token[i + 2]->type;
	if (token[i]->type & e_redir_out_trun && after_cmd)
		return (print_ambiguous_error(var_name), 0);
	else if (token[i]->type & e_redir_in && after_cmd)
		return (print_ambiguous_error(var_name), 0);
	else if (token[i]->type & e_redir_out_app && after_cmd)
		return (print_ambiguous_error(var_name), 0);
	return (1);
}

int	check_redir_after_pars(t_token **token, int i, int *index)
{
	int		after_cmd;
	char	**var_names;
	char	*var_name;

	var_names = g_all.variables_name->content;
	var_name = var_names[*index];
	if (token[i]->type & (e_redir_out_trun | e_redir_in | e_redir_out_app))
		(*index)++;
	after_cmd = token[i + 1] && e_file_name & token[i + 1]->type;
	if (token[i]->type & e_redir_out_trun && !after_cmd)
		return (print_ambiguous_error(var_name), 0);
	else if (token[i]->type & e_redir_in && !after_cmd)
		return (print_ambiguous_error(var_name), 0);
	else if (token[i]->type & e_redir_out_app && !after_cmd)
		return (print_ambiguous_error(var_name), 0);
	return (1);
}

int	ft_check_syntax_after_pars(void)
{
	t_token	**tokens;
	int		i;
	int		index;

	index = 0;
	tokens = g_all.tokens->content;
	g_all.cmd_error_status = 0;
	i = 0;
	while (tokens[i])
	{
		if (check_redir_double_file(tokens, i, &index) == 0)
			return (0);
		if (check_redir_after_pars(tokens, i, &index) == 0)
			return (0);
		i++;
	}
	return (1);
}
