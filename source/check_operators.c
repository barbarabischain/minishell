/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:43:52 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/30 11:37:22 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_pipe(t_node *tokens)
{
	int	operator;

	operator = PIPE;
	while (find_type(tokens, operator))
	{
		tokens = find_type(tokens, operator);
        if (tokens && tokens->prev == NULL)
            return (2);
		if (tokens && tokens->next == NULL)
			return (2);
        if (tokens && tokens->next->token == PIPE)
			return (2);
		if (tokens)
			tokens = tokens->next;
	}
	return (0);
}

int	check_out(t_node *tokens)
{
	int	operator;

	operator = OUT_R;
	while (find_type(tokens, operator))
	{
		tokens = find_type(tokens, operator);
		if (tokens && tokens->next == NULL)
			return (2);
        if (tokens && tokens->next->token == operator)
			return (2);
		if (tokens)
			tokens = tokens->next;
	}
	return (0);
}

int	check_in(t_node *tokens)
{
	int	operator;

	operator = IN_R;
	while (find_type(tokens, operator))
	{
		tokens = find_type(tokens, operator);
		if (tokens && tokens->next == NULL)
			return (2);
        if (tokens && tokens->next->token == operator)
			return (2);
		if (tokens)
			tokens = tokens->next;
	}
	return (0);
}

int	check_append(t_node *tokens)
{
	int	operator;

	operator = APPEND;
	while (find_type(tokens, operator))
	{
		tokens = find_type(tokens, operator);
		if (tokens && tokens->next == NULL)
			return (2);
        if (tokens && tokens->next->token == operator)
			return (2);
		if (tokens)
			tokens = tokens->next;
	}
	return (0);
}

int	check_heredoc(t_node *tokens)
{
	int	operator;

	operator = HEREDOC;
	while (find_type(tokens, operator))
	{
		tokens = find_type(tokens, operator);
		if (tokens && tokens->next == NULL)
			return (2);
        if (tokens && tokens->next->token == operator)
			return (2);
		if (tokens)
			tokens = tokens->next;
	}
	return (0);
}
