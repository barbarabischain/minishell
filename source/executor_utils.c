/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:20:30 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/18 20:33:06 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_existence(char *path, int i)
{
	char	*cmd_name;

	cmd_name = shell()->cmd_array[i][0];
	if (path)
		return ;
	if (shell()->cmd_array[i][0])
		ft_printf_fd(2, "minishell: %s: command not found\n", cmd_name);
	shell()->status = 127;
	execute_exit();
}

void	check_executable(char *path, int i)
{
	char	*cmd_name;

	cmd_name = shell()->cmd_array[i][0];
	if (access(path, X_OK) == 0)
		return ;
	if (shell()->cmd_array[i][0])
		ft_printf_fd(2, "minishell: %s: Permission denied\n", cmd_name);
	free(path);
	shell()->status = 126;
	execute_exit();
}
