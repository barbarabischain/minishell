/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:02 by babischa          #+#    #+#             */
/*   Updated: 2024/10/14 16:47:15 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_list(t_node *stack)
{
	if (stack)
	{
		while (stack != NULL)
		{
			printf("value=%s\n", stack->value);
			stack = stack->next;
		}
	}
}
