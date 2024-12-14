/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:31:06 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/14 13:44:15 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	(*validate(int type))(t_node *tokens)
{
	int	(*f[6])(t_node *tokens);

	f[0] = 0;
	f[PIPE] = check_pipe;
	f[OUT_R] = check_out;
	f[IN_R] = check_in;
	f[APPEND] = check_append;
	f[HEREDOC] = check_heredoc;
	return (f[type]);
}

t_node	*find_type(t_node *lst, int type)
{
	while (lst && lst->token != type)
		lst = lst->next;
	return (lst);
}

void	lexical_analyse(void)
{
	static int	operator[5] = {PIPE, IN_R, OUT_R, APPEND, HEREDOC};
	int			i;

	i = 0;
	shell()->status = 0;
	while (shell()->status == 0 && i < 5)
		shell()->status = validate(operator[i++])(shell()->cmd_list);
	if (shell()->status == 2)
		shell()->error_message = "minishell: syntax error near unexpected token: {token}\n";
}
