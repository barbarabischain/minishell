/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:49:38 by babischa          #+#    #+#             */
/*   Updated: 2024/09/30 14:01:43 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*new_node(char *content)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	new->value = content;
	new->token = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_node_front(t_node **node, t_node *new)
{
	if (node && new)
	{
		(*node)->prev = new;
		new->next = *node;
	}
}

t_node	*last_node(t_node *node)
{
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

void	add_node_last(t_node **node, t_node *new)
{
	t_node	*last;

	if (node)
	{
			last = last_node(*node);
			last->next = new;
			new->prev = last;
	}
}

void	print_list(t_node *stack)
{
	if (stack)
	{
		while (stack != NULL)
		{
			printf("value = %s\n", stack->value);
			stack = stack->next;
		}
	}
}
