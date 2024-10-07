/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/07 14:58:03 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// static int	var_end(char *var)
// {
// 	int i;

// 	i = 0;
// 	while (ft_isalpha(var[i]) || var[i] == '_')
// 		i++;
// 	return (i);
// }

static char	*to_string(t_node *temp)
{
	int		i;
	int		size;
	char	*str;

	size = list_size(temp);
	str = ft_calloc(size + 1, 1);
	i = 0;
	while (temp)
	{
		str[i++] = *(temp->value);
		temp = temp->next;
	}
	return (str);
}

void	expand_var(t_data *data, t_node	*token_node)
{
	t_node	*expand;
	t_node	*tmp;
	int		i;

	i = 0;
	data = NULL;
	expand = NULL;
	while (token_node->value[i])
	{
		tmp = new_node(ft_substr(&token_node->value[i++], 0, 1));
		add_node_last(&expand, tmp);
	}
	free(token_node->value);
	token_node->value = to_string(expand);
	free_list(&expand);
}

void    expand(t_data *data, t_node *token_node)
{
	while (token_node)
	{
		if (token_node->value[0] != '\'' && ft_strchr(token_node->value, '$'))
			expand_var(data, token_node);
		token_node = token_node->next;
	}

}
