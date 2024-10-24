/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/21 13:51:23 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_meta_character(char *actual)
{
	if (*actual == '|')
		return (1);
	else if (*actual == '>' && *(actual - 1) != '>')
		return (1);
	else if (*actual == '<' && *(actual - 1) != '<')
		return (1);
	return (0);
}

static char	*put_space_on(char *str)
{
	t_node	*temp;
	int		i;
	char	inside_qts;

	temp = NULL;
	i = 0;
	inside_qts = 0;
	while (str[i])
	{
		if (ft_strchr("\"\'", str[i]) && inside_qts == 0)
			inside_qts += str[i];
		else if (ft_strchr("\"\'", str[i]) && inside_qts)
			inside_qts -= str[i];
		if (!inside_qts && is_meta_character(&str[i]))
			add_node_last(&temp, new_node(ft_strdup(" ")));
		add_node_last(&temp, new_node(ft_substr(&str[i], 0, 1)));
		if (!inside_qts && is_meta_character(&str[i]) && ft_isalnum(str[i + 1]))
		 	add_node_last(&temp, new_node(ft_strdup(" ")));
		if (!inside_qts && str[i] == '>' && str[i - 1] == '>' && ft_isalnum(str[i + 1]))
			add_node_last(&temp, new_node(ft_strdup(" ")));
		if (!inside_qts && str[i] == '<' && str[i - 1] == '<' && ft_isalnum(str[i + 1]))
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
