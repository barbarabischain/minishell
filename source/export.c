/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:10:21 by babischa          #+#    #+#             */
/*   Updated: 2024/10/28 16:53:43 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_valid_name(char *name)
{
	int	i;

	i = 0;
	printf("\nname = %s\n", name);
	while (name[i])
	{
		if (!ft_isalpha(name[i]) || name[i] != '_' || name[i] != '=')
			return (-42);
		i++;
	}
	return (1);
}

void	export(char **matrix)
{
	int	i;

	i = 1;
	if (!matrix[i])
		print_matrix(sort_ascii(array_of_pointers(shell()->env_list)));
	else
	{
		while (matrix[i])
		{
			if (is_valid_name(matrix[i]))
				printf("valid variable name \n");
			else
				printf("FATAL ERROR: not a valid identifier\n");
			i++;
		}
	}
}
