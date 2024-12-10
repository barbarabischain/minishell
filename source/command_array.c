/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:44:55 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/08 09:43:47 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	count_commands(t_node *cmd_list)
{
	int	count;

	count = 1;
	while (cmd_list)
	{
		if (cmd_list->token == PIPE)
			count++;
		cmd_list = cmd_list->next;
	}
	return (count);
}

static int	count_tokens(t_node *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->token != PIPE)
	{
		count++;
		tokens = tokens->next;
	}
	return (count);
}

static char	**to_matrix(t_node **tokens)
{
	char	**cmd;
	int		i;
	int		tks_count;

	i = 0;
	tks_count = count_tokens(*tokens);
	cmd = ft_calloc(tks_count + 1, sizeof(void *));
	while (i < tks_count)
	{
		cmd[i++] = ft_strdup((*tokens)->value);
		*tokens = (*tokens)->next;
	}
	if (*tokens && (*tokens)->token == PIPE)
		*tokens = (*tokens)->next;
	return (cmd);
}

static void	build_aux(int qtd, t_node *tokens)
{
	int index;

	index = 0;
	while (tokens && index < qtd)
		shell()->cmd_array[index++] = remove_quotes(to_matrix(&tokens));
}

void build_command_array(void)
{
	int qtd;

	qtd = count_commands(shell()->cmd_list);
	shell()->cmd_array = ft_calloc(qtd + 1, sizeof(void *));
	if (qtd == 1)
		shell()->cmd_array[0] = remove_quotes(list_to_matrix(shell()->cmd_list));
	else
		build_aux(qtd, shell()->cmd_list);
	shell()->cmd_array_size = qtd;
}
