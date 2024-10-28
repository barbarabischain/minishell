/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:31:06 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/28 16:08:04 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*find_type(t_node *lst, int type)
{
	while (lst && lst->token != type)
		lst = lst->next;
	return (lst);
}

static int	open_operator(t_node *tokens, int op)
{
	while (find_type(tokens, op))
	{
		tokens = find_type(tokens, op);
		if (tokens && tokens->next == NULL)
			return (2);
		else if (tokens)
			tokens = tokens->next;
	}
	return (0);
}

void	lexical_analyse(void)
{
	static int	op[5] = {PIPE, IN_R, OUT_R, APPEND, HEREDOC};
	int			i;

	i = 0;
	shell()->status = 0;
	while (shell()->status == 0 && i < 5)
	{
		shell()->status = open_operator(shell()->cmd_list, op[i]);
		i++;
	}
}
