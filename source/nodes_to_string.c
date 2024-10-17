/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:22:45 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/17 18:22:59 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
