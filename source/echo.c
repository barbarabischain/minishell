/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:50:37 by babischa          #+#    #+#             */
/*   Updated: 2024/12/13 21:57:42 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	echo(char **cmd_array)
{
	int	i;
	int	n;

	i = 1;
	n = 42;
	if (cmd_array[i] && !ft_strncmp(cmd_array[i], "-n", 3))
	{
		i++;
		n = -1;
	}
	while (cmd_array[i])
		printf("%s", cmd_array[i++]);
		// if (i != matrix_len(cmd_array))
		// 	printf(" ");
	if (n != 42)
	{
		shell()->status = 0;
		return ;
	}
	else
		printf ("\n");
	shell()->status = 0;
}
