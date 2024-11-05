/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:12 by babischa          #+#    #+#             */
/*   Updated: 2024/11/05 14:26:19 by babischa         ###   ########.fr       */
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
		key = get_key(matrix[i]);
		unset_env(shell()->env_list, key);
		free (key);
		i++;
	}
	free_matrix(matrix);
}
