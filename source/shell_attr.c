/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:50:04 by babischa          #+#    #+#             */
/*   Updated: 2024/12/22 12:55:23 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_shell_attr(struct termios *fd, int *old_fd)
{
	*fd = (struct termios){0};
	tcgetattr(STDIN_FILENO, fd);
	*old_fd = dup(STDIN_FILENO);
}

void	cleanup_execution(struct termios *fd, int old_fd)
{
	execution_clean();
	tcsetattr(STDIN_FILENO, TCSANOW, fd);
	dup2(old_fd, STDIN_FILENO);
}
