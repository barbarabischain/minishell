/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:26 by babischa          #+#    #+#             */
/*   Updated: 2024/11/04 12:14:20 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**list_to_matrix(t_node *list)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = ft_calloc((list_size(list) + 1), sizeof(char *));
	while (list)
	{
		matrix[i] = ft_strdup(list->value);
		list = list->next;
		i++;
	}
	return (matrix);
}

void	free_matrix(char **mtx)
{
	int	i;

	if (mtx)
	{
		i = -1;
		while (mtx[++i])
			free(mtx[i]);
		free(mtx);
	}
}
