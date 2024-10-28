/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:02 by babischa          #+#    #+#             */
/*   Updated: 2024/10/28 12:00:22 by madias-m         ###   ########.fr       */
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
			printf("token_type=%d\n", stack->token);
			stack = stack->next;
		}
	}
}
