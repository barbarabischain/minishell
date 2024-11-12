/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:12:29 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/11 22:18:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	move(char *str)
{
	while (ft_strchr(str, -42))
		ft_memmove(ft_strchr(str, -42), \
		ft_strchr(str, -42) + 1, \
		ft_strlen(ft_strchr(str, -42)));
}

char	**remove_quotes(char **matrix)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	quote = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (ft_strchr("\'\"", matrix[i][j]) && quote == 0)
			{
				quote += matrix[i][j];
				matrix[i][j] = -42;
			}
			else if (ft_strchr("\'\"", matrix[i][j]) && quote == matrix[i][j])
			{
				quote -= matrix[i][j];
				matrix[i][j] = -42;
			}
			j++;
		}
		move(matrix[i++]);
	}
	return (matrix);
}
