/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/02 14:07:07 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**remove_quotes(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i][0] == '\"' || matrix[i][0] == '\'')
		{
			ft_memmove(matrix[i], &matrix[i][1], ft_strlen(&matrix[i][1] - 1));
			matrix[i][ft_strlen(matrix[i]) - 1] = '\0';
		}
		i++;
	}
	return (matrix);
}

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
			if (str[i] == quote)
				i++;
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
	print_list(list);
	unparse_space_in_quotes(list);
	free_matrix(matrix);
}
