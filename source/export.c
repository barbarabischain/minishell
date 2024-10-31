/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:10:21 by babischa          #+#    #+#             */
/*   Updated: 2024/10/31 13:44:54 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_export(t_env_list **array)
{
	while (*array)
	{
		printf("declare -x %s=\"%s\"\n", (*array)->key, (*array)->value);
		array++;
	}
}


int	is_valid_name(char	*name)
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

void	export_key(char *name)
{
	int	pos;

	if (!ft_strchr(name, '='))
		export_env(shell()->env_list, get_key(name), "teste");
	else
	{
		pos = ft_strchr(name, '=') - name;
		if (++pos)
			export_env(shell()->env_list, get_key(name), get_value(name));
		else
			export_env(shell()->env_list, get_key(name), ft_calloc(sizeof(char *), 1));
	}
}

void	export(char **matrix)
{
	int			i;

	i = 1;
	if (!matrix[i])
		print_export(sort_ascii(array_of_pointers(shell()->env_list)));
	else
	{
		while (matrix[i])
		{
			if (is_valid_name(matrix[i]))
				export_key(matrix[i]);
			else
				printf("FATAL ERROR: not a valid identifier\n");
			i++;
		}
	}
	//print_env(shell()->env_list);
	//print_matrix(sort_ascii(array_of_pointers(shell()->env_list)));
	free_matrix(matrix);
}
