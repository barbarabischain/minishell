/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:22:03 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/23 19:08:54 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_in(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		shell()->status = 1;
		if (access(file_name, F_OK) == 0)
			shell()->error_message = "sem permissao de leitura\n";
		else
			shell()->error_message = "arquivo nao existe!\n";
		return ;
	}
	dup2(fd, shell()->in_fd);
	shell()->in_fd = fd;
}
