/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/10 17:47:58 by babischa         ###   ########.fr       */
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
	if (var_end(&src->value[*i]) == 0)
		return (add_node_last(&*dest, new_node(ft_strdup("$"))));
	key = ft_substr(&src->value[*i], 0, var_end(&src->value[*i]));
	*i = *i + var_end(&src->value[*i]);
	found = lst_find(key);
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
	char		on_quote;
	int			i;

	i = 0;
	expand = NULL;
	on_quote = 0;
	while (token->value[i])
	{
		if (token->value[i] == '\'' && !on_quote)
			on_quote = 1;
		else if (token->value[i] == '\'' && on_quote)
			on_quote = 0;
		if (token->value[i] == '$' && !on_quote)
		{
			if (token->value[i + 1] && token->value[i + 1] == '?')
				expand_status(&expand, &i);
			else
				add_expansion(&expand, token, &i);
		}
		else
			add_literal(&expand, token, &i);
	}
	printf("");
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
		if (ft_strchr(token_node->value, '$'))
			expand_var(token_node);
		token_node = token_node->next;
	}
}
