/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:50:37 by babischa          #+#    #+#             */
/*   Updated: 2024/11/07 16:58:10 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	echo(char **cmd_matrix)
{
	int	i;
	int	n;

	i = 1;
	n = 42;
	if (cmd_matrix[i] && !ft_strncmp(cmd_matrix[i], "-n", 3))
	{
		i++;
		n = -1;
	}
	while (cmd_matrix[i])
	{
		printf("%s", cmd_matrix[i++]);
		if (i != matrix_len(cmd_matrix))
			printf(" ");
	}
	free_matrix(cmd_matrix);
	if (n != 42)
		return ;
	else
		printf ("\n");
}
