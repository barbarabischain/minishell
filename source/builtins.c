/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:40:57 by babischa          #+#    #+#             */
/*   Updated: 2024/11/05 14:03:39 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(t_node	*list)
{
	if (!ft_strncmp(list->value, "pwd", 4)
		|| !ft_strncmp(list->value, "echo", 5)
		|| !ft_strncmp(list->value, "export", 7)
		|| !ft_strncmp(list->value, "unset", 6))
		return (1);
	else
		return (0);
}

void	execute_builtins(t_node	*list)
{
	if (!ft_strncmp(list->value, "pwd", 4))
		pwd();
	if (!ft_strncmp(list->value, "echo", 5))
		echo(remove_quotes(list_to_matrix(list)));
	if (!ft_strncmp(list->value, "export", 7))
		export(remove_quotes(list_to_matrix(list)));
	if (!ft_strncmp(list->value, "unset", 6))
		unset(remove_quotes(list_to_matrix(list)));
}
