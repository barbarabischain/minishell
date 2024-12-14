/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:20 by babischa          #+#    #+#             */
/*   Updated: 2024/12/14 13:49:19 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	expand_status(t_node **dest, int *i)
{
	int		j;
	char	*status;
	t_node	*node;

	status = ft_itoa(shell()->status);
	j = 0;
	while (status[j])
	{
		node = new_node(ft_substr(&status[j], 0, 1));
		add_node_last(dest, node);
		j++;
	}
	free(status);
	*i = *i + 2;
}
