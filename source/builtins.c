/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:40:57 by babischa          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:53 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	is_builtin(t_node	*list)
{
	if (!ft_strncmp(list->value, "pwd", 4))
		pwd();
	if (!ft_strncmp(list->value, "echo", 5))
		echo(remove_quotes(list_to_matrix(list)));
	if (!ft_strncmp(list->value, "export", 7))
		export(remove_quotes(list_to_matrix(list)));
}
