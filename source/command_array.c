/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:44:55 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/14 13:57:31 by madias-m         ###   ########.fr       */
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

static void	build_aux(char ***cmd_array, int qtd, t_node *tokens)
{
	int	index;

	index = 0;
	while (tokens && index < qtd)
		cmd_array[index++] = remove_quotes(to_matrix(&tokens));
}

void	build_command_array(void)
{
	int		qtd;
	char	***cmd_array;

	qtd = count_commands(shell()->cmd_list);
	cmd_array = ft_calloc(qtd + 1, sizeof (void *));
	if (qtd == 1)
		cmd_array[0] = remove_quotes(list_to_matrix(shell()->cmd_list));
	else
		build_aux(cmd_array, qtd, shell()->cmd_list);
	shell()->cmd_array = cmd_array;
	shell()->cmd_array_size = qtd;
}
