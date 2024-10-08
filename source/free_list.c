/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:39:30 by babischa          #+#    #+#             */
/*   Updated: 2024/10/09 11:58:20 by madias-m         ###   ########.fr       */
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
