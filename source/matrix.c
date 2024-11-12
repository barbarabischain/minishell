/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:26 by babischa          #+#    #+#             */
/*   Updated: 2024/11/11 22:25:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	matrix_len(char	**matrix)
{
	int	count;

	count = 0;
	while (*matrix++)
		count++;
	return (count);
}

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
