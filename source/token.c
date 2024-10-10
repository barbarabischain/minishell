/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/10 17:11:14 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_meta_character(char *actual)
{
	if (*actual == '|' || *actual == '<')
		return (1);
	else if (*actual == '>' && *(actual - 1) != '>')
		return (1);
	return (0);
}

char *put_space_on(char *str)
{
	t_node *temp;
	int		i;

	i = 0;
	temp = NULL;
	while (str[i])
	{
		if (is_meta_character(&str[i]))
			add_node_last(&temp, new_node(ft_strdup(" ")));
		add_node_last(&temp, new_node(ft_substr(&str[i], 0, 1)));
		if (is_meta_character(&str[i]) && ft_isalnum(str[i + 1]))
			add_node_last(&temp, new_node(ft_strdup(" ")));
		else if (str[i] == '>' && str[i - 1] == '>' && ft_isalnum(str[i + 1]) )
			add_node_last(&temp, new_node(ft_strdup(" ")));
		i++;
	}
	free(str);
	str = nodes_to_string(temp);
	free_list(&temp);
	return (str);
}

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
				if (str[i                                                                                                                                                                                                                                                                                                     ] == ' ')
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

void	token(char *str)
{
	char	**matrix;
	t_node	*list;
	int		i;

	i = 0;
	list = NULL;
	str = put_space_on(str);
	parse_space_in_quotes(str, '\"');
	parse_space_in_quotes(str, '\'');
	matrix = ft_split(str, ' ');
	free(str);
	while (matrix[i])
	{
		if (!list)
			list = new_node(ft_strdup(matrix[i]));
		else
			add_node_last(&list, new_node(ft_strdup(matrix[i])));
		i++;
	}
	get_data()->cmd_list = list;
	//print_list(list);
	unparse_space_in_quotes(list);
	expand(list);
	//print_list(list);
	free_matrix(matrix);
}
