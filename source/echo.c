/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:50:37 by babischa          #+#    #+#             */
/*   Updated: 2024/10/17 11:12:59 by babischa         ###   ########.fr       */
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

void	echo(char **matrix)
{
	int	i;
	int	n;

	i = 1;
	n = 42;
	if (matrix[i] && !ft_strncmp(matrix[i], "-n", 3))
	{
		i++;
		n = -1;
	}
	while (matrix[i])
	{
		printf("%s", matrix[i++]);
		if(i != matrix_len(matrix))
			printf(" ");
	}
	free_matrix(matrix);
	if (n != 42)
	 	return ;
	else
		printf ("\n");
}
