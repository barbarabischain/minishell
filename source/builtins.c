/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:40:57 by babischa          #+#    #+#             */
/*   Updated: 2024/10/28 15:39:09 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	is_builtin(t_node	*list)
{
	if (!ft_strncmp(list->value, "pwd", 3))
		pwd();
	// if (!ft_strncmp(list->value, "echo", 4))
	// 	echo(remove_quotes(list_to_matrix(list)));
	if (!ft_strncmp(list->value, "export", 6))
		export(remove_quotes(list_to_matrix(list)));
}
