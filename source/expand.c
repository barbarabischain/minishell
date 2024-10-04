/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/04 20:12:03 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	var_end(char *var)
{
	int i;

	i = 0;
	while (ft_isalpha(var[i]) || var[i] == '_')
		i++;
	return (i);
}

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

static void	expand_var(t_data *data, t_node *token_node)
{
	t_node		*temp;
	t_env_list	*found;
	char 		*key;
	int 		key_len;
	int			i;

	i = 0;
	temp = NULL;
	while (token_node->value[i])
	{
		if (token_node->value[i] == '$')
		{
			key_len = var_end(&token_node->value[++i]);
			// printf("key_len: %d\n", key_len);
			key = ft_substr(&token_node->value[i], 0, key_len);
			// printf("key: %s\n", key);
			i += key_len;
			found = lst_find(data->env_list, key);
			if (found)
			{
				key_len = 0;
				while (found->value[key_len])
					add_node_last(&temp, new_node(&found->value[key_len++]));
			}
		}
		else
			add_node_last(&temp, new_node(&token_node->value[i++]));
	}
	free(token_node->value);
	// print_list(temp);
	token_node->value = to_string(temp);
	printf("value: %s\n", token_node->value);
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