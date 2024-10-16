/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:49:38 by babischa          #+#    #+#             */
/*   Updated: 2024/10/14 16:46:47 by babischa         ###   ########.fr       */
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

	if (*node)
	{
		last = last_node(*node);
		last->next = new;
		new->prev = last;
	}
	else
		*node = new;
}

int	list_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
