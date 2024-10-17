/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:12:29 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/17 18:13:52 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**remove_quotes(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i][0] == '\"' || matrix[i][0] == '\'')
		{
			ft_memmove(matrix[i], &matrix[i][1], ft_strlen(&matrix[i][1] - 1));
			matrix[i][ft_strlen(matrix[i]) - 1] = '\0';
		}
		i++;
	}
	return (matrix);
}
