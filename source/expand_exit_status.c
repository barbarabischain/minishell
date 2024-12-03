/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:20 by babischa          #+#    #+#             */
/*   Updated: 2024/12/03 16:11:11 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	expand_exit_status(t_node *token_node)
{
	t_node	*tmp;

	tmp = token_node;
	free(token_node->value);
	tmp->value = ft_itoa(shell()->status);
}
