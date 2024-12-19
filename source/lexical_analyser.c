/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:31:06 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/19 17:11:55 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	set_error_message(char *token_value)
{
	shell()->error_message = \
	ft_strdup("minishell: syntax error near unexpected token: `%s'\n");
	shell()->target_error = ft_strdup(token_value);
	return (2);
}

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
	static int	operator[5] = {IN_R, OUT_R, APPEND, HEREDOC, PIPE};
	int			i;

	i = 0;
	shell()->status = 0;
	while (shell()->status == 0 && i < 5)
		shell()->status = validate(operator[i++])(shell()->cmd_list);
	if (shell()->status == 2)
		ft_printf_fd(2, shell()->error_message, shell()->target_error);
}
