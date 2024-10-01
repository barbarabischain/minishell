/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/01 00:09:56 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int	contains_quotes(char *str)
{
	char 	*first;
	char 	*second;
	int		contains_space;

	first = ft_strchr(str, '\"');
	if (!first)
		return (0);
	second = ft_strchr(first + 1, '\"');
	contains_space = 0;
	while (++first < second)
	{
		if (*first == ' ')
			contains_space = 1;
	}
	return (contains_space);
}

char *part(char **str)
{
	char	*part;
	int 	size;
	int 	i;

	if (**str == '\"')
	{
		(*str)++;
		size = ft_strchr(*str, '\"') - *str;
	}
	else
		size = ft_strchr(*str, '\"') - *str;
	if (size < 1)
		return (ft_calloc(1, sizeof(char)));
	part = ft_calloc(size + 1, sizeof(char));
	i = -1;
	while (++i < size)
		part[i] = (*str)[i];
	(*str) += size + 1;
	return (part);
}

char	**ft_split_plus(char *str)
{
	t_node	*lst;
	t_node	*head;
	char 	**matrix;
	int		part_count;
	int		i;
	
	lst = NULL;
	while (*str)
	{
		if (!lst)
			lst = new_node(part(&str));
		else
			add_node_last(&lst, new_node(part(&str)));
	}
	part_count = list_size(lst);
	matrix = ft_calloc(part_count + 1, sizeof(void *));
	i = 0;
	head = lst;
	while (lst)
	{
		matrix[i++] = ft_strdup(lst->value);
		lst = lst->next;
	}
	free_list(&head);
	return (matrix);
}

void	token(char *str, t_data *data)
{
	char	**matrix;
	t_node	*list;
	int		i;

	i = 0;
	list = NULL;
	if (contains_quotes(str))
		matrix = ft_split_plus(str);
	else	
		matrix = ft_split(str, ' ');
	while (matrix[i])
	{
		if (!list)
			list = new_node(ft_strdup(matrix[i]));
		else
			add_node_last(&list, new_node(ft_strdup(matrix[i])));
		i++;
	}
	data->cmd_list = list;
	//print_list(list);
	free_matrix(matrix);
}