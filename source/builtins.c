/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:40:57 by babischa          #+#    #+#             */
/*   Updated: 2024/12/02 12:29:35 by babischa         ###   ########.fr       */
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
		|| !ft_strncmp(*cmd_array, "env", 4))
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
	if (!ft_strncmp(*cmd_array, "export", 5))
	 	export(cmd_array);
	if (!ft_strncmp(*cmd_array, "unset", 6))
	 	unset(cmd_array);
	if (!ft_strncmp(*cmd_array, "cd", 3))
		cd(cmd_array);
	if (!ft_strncmp(*cmd_array, "env", 6))
		env(cmd_array);

}
