/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:24:01 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/18 17:23:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	classify(t_node *tokens)
{
	while (tokens)
	{
		tokens->token = token_type(tokens->value);
		tokens = tokens->next;
	}
}
