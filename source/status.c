/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:20 by babischa          #+#    #+#             */
/*   Updated: 2024/12/16 14:53:34 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	expand_status(t_node **dest, int *i)
{
	int		j;
	char	*status;
	t_node	*node;

	status = ft_itoa(g_signal);
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
