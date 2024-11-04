/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:10:21 by babischa          #+#    #+#             */
/*   Updated: 2024/11/04 12:43:05 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_ptr_array(t_env_list **list)
{
	if (list)
		free(list);
	list = NULL;
}

void	print_export(t_env_list **array)
{
	while (*array)
	{
		if ((*array)->value == NULL)
			printf("declare -x %s\n", (*array)->key);
		else
			printf("declare -x %s=\"%s\"\n", (*array)->key, (*array)->value);
		array++;
	}
}

int	is_valid_name(char	*name)
{
	int	i;

	i = 0;
	if (ft_isdigit(name[0]))
        return (0);
	while (name[i] && name[i] != '=')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export_key(char *name)
{
	int	pos;

	if (!ft_strchr(name, '='))
		export_env(shell()->env_list, ft_strdup(name), NULL);
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
	t_env_list	**ptr_array;

	i = 1;
	ptr_array = array_of_pointers(shell()->env_list);
	if (!matrix[i])
		print_export(sort_ascii(ptr_array));
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
	free_matrix(matrix);
	free_ptr_array(ptr_array);
}
