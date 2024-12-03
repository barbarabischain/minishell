/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:12:29 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/03 11:46:38 by madias-m         ###   ########.fr       */
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

static void	remove_quotes_aux(char *str, int j, char *quote)
{
	if (ft_strchr("\'\"", str[j]) && *quote == 0)
	{
		*quote += str[j];
		str[j] = -42;
	}
	else if (ft_strchr("\'\"", str[j]) && *quote == str[j])
	{
		*quote -= str[j];
		str[j] = -42;
	}
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
			remove_quotes_aux(matrix[i], j++, &quote);
		move(matrix[i++]);
	}
	return (matrix);
}
