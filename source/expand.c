/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/17 18:23:23 by madias-m         ###   ########.fr       */
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

static void	expand_var(t_node	*token)
{
	t_node		*expand;
	t_env_list	*found;
	char		*key;
	int			i;
	int			j;

	i = 0;
	expand = NULL;
	while (token->value[i])
	{
		if (token->value[i] != '$')
			add_node_last(&expand, new_node(ft_substr(&token->value[i++], 0, 1)));
		else
		{
			i++;
			key = ft_substr(&token->value[i], 0, var_end(&token->value[i]));
			i += var_end(&token->value[i]);
			found = lst_find(shell()->env_list, key);
			if (found)
			{
				j = 0;
				while (found->value[j])
					add_node_last(&expand, new_node(ft_substr(&found->value[j++], 0, 1)));
			}
			else
				add_node_last(&expand, new_node(ft_strdup(" ")));
			free(key);
		}
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
