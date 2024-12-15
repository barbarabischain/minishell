/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:22:03 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/15 14:30:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_in(char *file_name)
{
	int	fd;
	int	new_fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		shell()->status = 1;
		if (access(file_name, F_OK) == 0)
			shell()->error_message = \
			ft_strdup("minishell: Permission denied\n");
		else
			shell()->error_message = \
			ft_strdup("minishell: %s: No such file or directory\n");
		shell()->target_error = ft_strdup(file_name);
		return ;
	}
	new_fd = dup2(fd, shell()->in_fd);
	shell()->in_fd = new_fd;
	close(fd);
}
