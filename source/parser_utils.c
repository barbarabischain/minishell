/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:21:41 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/14 12:42:55 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static	void	quote_handler(char *inside_quotes, char actual_char)
{
	if (ft_strchr("\"\'", actual_char) && *inside_quotes == 0)
		*inside_quotes += actual_char;
	else if (ft_strchr("\"\'", actual_char) && *inside_quotes == actual_char)
		*inside_quotes -= actual_char;
}

static int	is_meta(char c)
{
	return (c == '<' || c == '>');
}

static void		space(t_node *node)
{
	char first;
	char second;
	t_node *space_node;
	
	if (!node || !node->next || node->value[0] == ' ')
		return ;
	first = node->value[0];
	second = node->next->value[0];
	if (second == ' ')
		return ;
	if (is_meta(first) && is_meta(second) && first == second)
	{
		space_node = new_node(ft_strdup(" "));
		if (node->next->next)
		{
			node->next->next->prev = space_node;
			space_node->next = node->next->next;
		}
		space_node->prev = node->next;
		node->next->next = space_node;
	}
	else if (is_meta(first) && !is_meta(second))
	{
		space_node = new_node(ft_strdup(" "));
		space_node->prev = node;
		space_node->next = node->next;
		node->next->prev = space_node;
		node->next = space_node;
	}
	else if (is_meta(first) && is_meta(second) && first != second)
	{
		space_node = new_node(ft_strdup(" "));
		space_node->prev = node;
		space_node->next = node->next;
		node->next->prev = space_node;
		node->next = space_node;
	}
	else if (!is_meta(first) && is_meta(second))
	{
		space_node = new_node(ft_strdup(" "));
		space_node->prev = node;
		space_node->next = node->next;
		node->next->prev = space_node;
		node->next = space_node;
	}
}

char	*put_spaces(char *str)
{
	t_node	*head;
	t_node	*aux;
	int		i;
	char	qts;

	head = NULL;
	i = 0;
	qts = 0;
	while (str[i])
		add_node_last(&head, new_node(ft_substr(&str[i++], 0, 1)));
	free(str);
	aux = head;
	while (aux)
	{
		quote_handler(&qts, aux->value[0]);
		if (!qts)
			space(aux);
		aux = aux->next;
	}
	str = nodes_to_string(head);
	free_list(&head);
	return (str);
}
