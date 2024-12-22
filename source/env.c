/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:38:31 by babischa          #+#    #+#             */
/*   Updated: 2024/12/22 14:26:05 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env(char **matrix)
{
	int	i;

	i = 1;
	while (matrix[i])
	{
		if (!is_valid_name(matrix[i]) || !ft_strchr(matrix[i], '='))
		{
			ft_printf_fd(2, "env: syntax error\n");
			shell()->status = 2;
			return ;
		}
		i++;
	}
	i = 1;
	print_env(shell()->env_list);
	while (matrix[i])
		printf("%s\n", matrix[i++]);
	shell()->status = 0;
}
