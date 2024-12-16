/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:03:42 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/15 14:28:59 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_out(char *file_name)
{
	int	fd;
	int	new_fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0 && access(file_name, F_OK) == 0)
	{
		shell()->status = 1;
		shell()->error_message = ft_strdup("minishell: %s: Permission denied\n");
		shell()->target_error = ft_strdup(file_name);
		return ;
	}
	new_fd = dup2(fd, shell()->out_fd);
	shell()->out_fd = new_fd;
	close(fd);
}
