/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:40:57 by babischa          #+#    #+#             */
/*   Updated: 2024/12/19 18:49:29 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(char	**cmd_array)
{
	if (!ft_strncmp(*cmd_array, "pwd", 4)
		|| !ft_strncmp(*cmd_array, "echo", 5)
		|| !ft_strncmp(*cmd_array, "export", 5)
		|| !ft_strncmp(*cmd_array, "unset", 6)
		|| !ft_strncmp(*cmd_array, "cd", 3)
		|| !ft_strncmp(*cmd_array, "env", 4)
		|| !ft_strncmp(*cmd_array, "exit", 5))
		return (1);
	else
		return (0);
}

void	execute_builtins(char	**cmd_array)
{
	if (!ft_strncmp(*cmd_array, "pwd", 4))
		pwd();
	if (!ft_strncmp(*cmd_array, "echo", 5))
		echo(cmd_array);
	if (!ft_strncmp(*cmd_array, "export", 7))
		export(cmd_array);
	if (!ft_strncmp(*cmd_array, "unset", 6))
		unset(cmd_array);
	if (!ft_strncmp(*cmd_array, "cd", 3))
		cd(cmd_array);
	if (!ft_strncmp(*cmd_array, "env", 4))
		env(cmd_array);
	if (!ft_strncmp(*cmd_array, "exit", 5))
		check_exit(cmd_array);
}
