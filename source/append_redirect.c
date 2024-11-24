/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:38:29 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/24 08:51:05 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_append(char *file_name)
{
	int	fd;

	fd = open(file_name, O_APPEND);
	if (fd < 0 && access(file_name, F_OK) == 0)
	{
		shell()->status = 1;
		shell()->error_message = "sem permissao de escrita\n";
		return ;
	}
	fd = open(file_name, O_APPEND | O_CREAT | O_TRUNC, 0644);
	dup2(fd, shell()->out_fd);
	shell()->out_fd = fd;
}