/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/09 11:35:50 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	var_end(char *var)
{
	int i;

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

void	expand_var(t_data *data, t_node	*token_node)
{
	t_node	*expand;
	t_node	*tmp;
	t_env_list	*found;
	char	*key;
	int		i;
	int		j;

	i = 0;
	expand = NULL;
	while (token_node->value[i])
	{
		if (token_node->value[i] != '$')
		{
			tmp = new_node(ft_substr(&token_node->value[i++], 0, 1));
			add_node_last(&expand, tmp);
		}
		else
		{
			i++;
			key = ft_substr(&token_node->value[i], 0, var_end(&token_node->value[i]));
			i += var_end(&token_node->value[i]);
			found = lst_find(data->env_list, key);
			if (found)
			{
				j = 0;
				while (found->value[j])
				{
					tmp = new_node(ft_substr(&found->value[j++], 0, 1));
					add_node_last(&expand, tmp);
				}
			}
			else
				add_node_last(&expand, new_node(ft_strdup(" ")));
			free(key);
		}
	}
	free(token_node->value);
	token_node->value = nodes_to_string(expand);
	printf("v: %s\n",token_node->value);
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
