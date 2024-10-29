/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:10:21 by babischa          #+#    #+#             */
/*   Updated: 2024/10/29 14:46:50 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_valid_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '=')
	{
		if (!ft_isalpha(name[i]) || name[i] != '_')
			return (-42);
		i++;
	}
	return (1);
}

void	export(char **matrix)
{
	int			i;

	i = 1;
	if (!matrix[i])
		print_matrix(sort_ascii(array_of_pointers(shell()->env_list)));
	else
	{
		while (matrix[i])
		{
			if (is_valid_name(matrix[i]))
			{
				export_env(shell()->env_list, get_key(matrix[i]), get_value(matrix[i]));
			}
			else
				printf("FATAL ERROR: not a valid identifier\n");
			i++;
		}
	}
	print_matrix(sort_ascii(array_of_pointers(shell()->env_list)));
	free_matrix(matrix);
}
