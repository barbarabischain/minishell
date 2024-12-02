/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:12 by babischa          #+#    #+#             */
/*   Updated: 2024/12/02 12:24:41 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	unset(char	**matrix)
{
	int		i;
	char	*key;

	i = 1;
	while (matrix[i])
	{
		if (is_valid_name(matrix[i]) && !ft_strchr(matrix[i], '='))
		{
			key = get_key(matrix[i]);
			unset_env(shell()->env_list, key);
			free (key);
		}
		else
		{
			printf("'%s': not a valid identifier\n", matrix[i]);
			exit_status(1);
		}
		i++;
	}
	exit_status(0);
}
