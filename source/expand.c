/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/15 15:59:06 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	var_end(char *var)
{
	int	i;

	i = 0;
	while (ft_isalnum(var[i]) || var[i] == '_')
		i++;
	return (i);
}

char	*nodes_to_string(t_node *temp)
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

void	expand_variable(char *key, t_node **expand)
{
	int			j;
	t_env_list	*found;
	t_node		*tmp;

	found = lst_find(get_data()->env_list, key);
	if (found)
	{
		j = 0;
		while (found->value[j])
		{
			tmp = new_node(ft_substr(&found->value[j++], 0, 1));
			add_node_last(expand, tmp);
		}
	}
	else
		add_node_last(expand, new_node(ft_strdup(" ")));
	free(key);
}

void	expand_var(t_node	*token_n)
{
	t_node		*expand;
	t_node		*tmp;
	char		*key;
	int			i;

	i = 0;
	expand = NULL;
	while (token_n->value[i])
	{
		if (token_n->value[i] != '$')
		{
			tmp = new_node(ft_substr(&token_n->value[i++], 0, 1));
			add_node_last(&expand, tmp);
		}
		else
		{
			i++;
			key = ft_substr(&token_n->value[i], 0, var_end(&token_n->value[i]));
			i += var_end(&token_n->value[i]);
			expand_variable(key, &expand);
		}
	}
	free(token_n->value);
	token_n->value = nodes_to_string(expand);
	printf("v: %s\n", token_n->value);
	free_list(&expand);
}

void	expand(t_node *token_node)
{
	while (token_node)
	{
		if (token_node->value[0] != '\'' && ft_strchr(token_node->value, '$'))
			expand_var(token_node);
		token_node = token_node->next;
	}
}
