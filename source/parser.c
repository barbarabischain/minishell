/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/17 18:12:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_meta_character(char *actual)
{
	if (*actual == '|' || *actual == '<')
		return (1);
	else if (*actual == '>' && *(actual - 1) != '>')
		return (1);
	return (0);
}

static char	*put_space_on(char *str)
{
	t_node	*temp;
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
		else if (str[i] == '>' && str[i - 1] == '>' && ft_isalnum(str[i + 1]))
			add_node_last(&temp, new_node(ft_strdup(" ")));
		i++;
	}
	free(str);
	str = nodes_to_string(temp);
	free_list(&temp);
	return (str);
}

int	count_quotes(char *str)
{
	int		count_double;
	int		count_simple;
	char	*temp;

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
	int	i;

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

void	parse_input(void)
{
	shell()->input = put_space_on(shell()->input);
	parse_space_in_quotes(shell()->input, '\"');
	parse_space_in_quotes(shell()->input, '\'');
}
