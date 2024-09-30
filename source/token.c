/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/09/30 16:37:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	token(char *str, t_data *data)
{
	char	**matrix;
	t_node	*list;
	int		i;

	i = 0;
	list = NULL;
	matrix = ft_split(str, ' ');
	while (matrix[i])
	{
		if (!list)
			list = new_node(ft_strdup(matrix[i]));
		else
			add_node_last(&list, new_node(ft_strdup(matrix[i])));
		i++;
	}
	data->cmd_list = list;
	print_list(list);
	free_matrix(matrix);
}