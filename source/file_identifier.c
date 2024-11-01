/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:05:39 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/01 12:20:30 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	identifie_files(void)
{
    t_node	*head;

	head = shell()->cmd_list;
	while (head)
	{
		if (head->token == 0 && head->prev)
		{
			if (head->prev->token == IN_R)
				head->token = F_READ;
			else if (head->prev->token == OUT_R)
				head->token = F_WRITE;
			else if (head->prev->token == APPEND)
				head->token = F_WRITE;
		}
		head = head->next;
	}
}