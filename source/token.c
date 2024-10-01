/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/01 12:37:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int	count_quotes(char *str)
{
	int		count_double;
	int		count_simple;
	char 	*temp;

	temp = str;
	count_double = 0;
	while (ft_strchr(temp, '\"'))
	{
		count_double++;
		temp = ft_strchr(temp, '\"') + 1;
	}
	if (count_double % 2)
		return (0);
	count_simple = 0;
	temp = str;
	while (ft_strchr(temp, '\''))
	{
		count_simple++;
		temp = ft_strchr(temp, '\'') + 1;
	}
	return (!(count_simple % 2));
}

void	parse_space_in_quotes(char *str, char quote)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == quote)
		{
			i++;
			while (str[i] && str[i] != quote)
			{
				if (str[i] == ' ')
					str[i] = -42;
				i++;
			}
		}
		else
			i++;
	}
}

void	unparse_space_in_quotes(t_node *list)
{
	while (list)
	{
		while (ft_strchr(list->value, -42))
			(*ft_strchr(list->value, -42)) = ' ';
		list = list->next;
	}
}

void	token(char *str, t_data *data)
{
	char	**matrix;
	t_node	*list;
	int		i;

	i = 0;
	list = NULL;
	// if (count_quotes(str))
	// {
		parse_space_in_quotes(str, '\"');
		parse_space_in_quotes(str, '\'');
	// }
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
	unparse_space_in_quotes(list);
	print_list(list);
	free_matrix(matrix);
}