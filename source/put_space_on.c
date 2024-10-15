/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_space_on.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:06:57 by babischa          #+#    #+#             */
/*   Updated: 2024/10/15 14:07:19 by babischa         ###   ########.fr       */
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

char	*put_space_on(char *str)
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
