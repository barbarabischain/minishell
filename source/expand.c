/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/18 13:50:42 by madias-m         ###   ########.fr       */
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

static void	add_literal(t_node **dest, t_node *src, int *i)
{
	t_node	*node;

	node = new_node(ft_substr(&src->value[*i], 0, 1));
	(*i)++;
	add_node_last(&*dest, node);
}

static void	add_expansion(t_node **dest, t_node *src, int *i)
{
	int			j;
	char		*key;
	t_env_list	*found;
	t_node		*node;

	(*i)++;
	key = ft_substr(&src->value[*i], 0, var_end(&src->value[*i]));
	*i = *i + var_end(&src->value[*i]);
	found = lst_find(shell()->env_list, key);
	if (found)
	{
		j = 0;
		while (found->value[j])
		{
			node = new_node(ft_substr(&found->value[j++], 0, 1));
			add_node_last(&*dest, node);
		}
	}
	else
		add_node_last(&*dest, new_node(ft_strdup(" ")));
	free(key);
}

static void	expand_var(t_node	*token)
{
	t_node		*expand;
	int			i;

	i = 0;
	expand = NULL;
	while (token->value[i])
	{
		if (token->value[i] != '$')
			add_literal(&expand, token, &i);
		else
			add_expansion(&expand, token, &i);
	}
	free(token->value);
	token->value = nodes_to_string(expand);
	free_list(&expand);
}

void	expand(void)
{
	t_node	*token_node;

	token_node = shell()->cmd_list;
	while (token_node)
	{
		if (token_node->value[0] != '\'' && ft_strchr(token_node->value, '$'))
			expand_var(token_node);
		token_node = token_node->next;
	}
}
