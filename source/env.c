/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:38:31 by babischa          #+#    #+#             */
/*   Updated: 2024/12/16 19:13:29 by babischa         ###   ########.fr       */
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
			printf("env: syntax error\n");
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
