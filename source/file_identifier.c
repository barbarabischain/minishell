/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:05:39 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/04 18:05:12 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	identifie_files(void)
{
    t_node	*head;

	head = shell()->cmd_list->next;
	while (head)
	{
		if (head->token == WORD)
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

static int	try_open_as(char *file_name, int open_as)
{
	int	fd;
	
	if (open_as == F_READ)
		fd = open(file_name, O_RDONLY);
	else
		fd = open(file_name, O_WRONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

void	check_files(void)
{
	t_node *tkns;

	tkns = shell()->cmd_list->next;
	while (tkns && shell()->status == 0)
	{
		if (tkns->token == F_READ || tkns->token == F_WRITE)
			shell()->status = try_open_as(tkns->value, tkns->token);
		tkns = tkns->next;
	}
}