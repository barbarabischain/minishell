/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:39:30 by babischa          #+#    #+#             */
/*   Updated: 2024/11/01 20:15:31 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_list(t_node **list)
{
	t_node	*current;
	t_node	*tmp;

	if (list != NULL)
	{
		if (list)
		{
			current = *list;
			while (current != NULL)
			{
				tmp = current;
				current = current->next;
				free(tmp->value);
				free(tmp);
			}
			*list = NULL;
		}
	}
}
