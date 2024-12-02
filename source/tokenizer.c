/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:11:18 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/27 17:49:43 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	unparse_space_in_quotes(t_node *list)
{
	while (list)
	{
		while (ft_strchr(list->value, -42))
			(*ft_strchr(list->value, -42)) = ' ';
		list = list->next;
	}
}

void	tokenize(void)
{
	char	**matrix;
	t_node	*list;
	int		i;

	i = 0;
	list = NULL;
	matrix = ft_split(shell()->input, ' ');
	free(shell()->input);
	while (matrix[i])
	{
		if (!list)
			list = new_node(ft_strdup(matrix[i]));
		else
			add_node_last(&list, new_node(ft_strdup(matrix[i])));
		i++;
	}
	free_matrix(matrix);
	unparse_space_in_quotes(list);
	classify(list);
	shell()->cmd_list = list;
	//print_list(list);
}
