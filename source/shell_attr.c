/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:50:04 by babischa          #+#    #+#             */
/*   Updated: 2024/12/22 14:13:26 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_shell_attr(void)
{
	shell()->fd = (struct termios){0};
	tcgetattr(STDIN_FILENO, &shell()->fd);
	shell()->old_fd = dup(STDIN_FILENO);
}

void	cleanup_execution(void)
{
	execution_clean();
	tcsetattr(STDIN_FILENO, TCSANOW, &shell()->fd);
	dup2(shell()->old_fd, STDIN_FILENO);
	close(shell()->old_fd);
}
