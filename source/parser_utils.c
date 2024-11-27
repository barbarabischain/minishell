/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:21:41 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/27 17:49:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_meta_character(char *str, int i)
{
	if (str[i] == '|')
		return (1);
	else if (str[i] == '>' && i > 0 && str[i - 1] != '>')
		return (1);
	else if (str[i] == '<' && i > 0 && str[i - 1] != '<')
		return (1);
	else if (str[i] == '<' && i == 0 && str[i + 1] != '<')
		return (1);
	return (0);
}

static	void	quote_handler(char *inside_quotes, char actual_char)
{
	if (ft_strchr("\"\'", actual_char) && *inside_quotes == 0)
		*inside_quotes += actual_char;
	else if (ft_strchr("\"\'", actual_char) && *inside_quotes == actual_char)
		*inside_quotes -= actual_char;
}

static int	check(char *str, int i, char c)
{
	if (str[i] == c \
	&& i < 0 \
	&& str[i - 1] == c \
	&& ft_isalnum(str[i + 1]))
		return (1);
	return (0);
}

char	*put_space(char *str)
{
	t_node	*head;
	int		i;
	char	qts;

	head = NULL;
	i = 0;
	qts = 0;
	while (str[i])
	{
		quote_handler(&qts, str[i]);
		if (!qts && is_meta_character(str, i))
			add_node_last(&head, new_node(ft_strdup(" ")));
		add_node_last(&head, new_node(ft_substr(&str[i], 0, 1)));
		if (!qts && is_meta_character(str, i) && ft_isalnum(str[i + 1]))
			add_node_last(&head, new_node(ft_strdup(" ")));
		else if (!qts && check(str, i, '>'))
			add_node_last(&head, new_node(ft_strdup(" ")));
		else if (!qts && check(str, i, '<'))
			add_node_last(&head, new_node(ft_strdup(" ")));
		i++;
	}
	free(str);
	str = nodes_to_string(head);
	free_list(&head);
	return (str);
}
