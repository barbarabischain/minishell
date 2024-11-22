/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:09:10 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/22 12:50:00 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_redirect(char *token)
{
	if (!ft_strncmp(token, ">", 2))
		return (1);
	else if (!ft_strncmp(token, "<", 2))
		return (1);
	else if (!ft_strncmp(token, ">>", 3))
		return (1);
	else if (!ft_strncmp(token, "<<", 3))
		return (1);
	return (0);
}

void	redirect(char **cmd)
{
    while (is_redirect(cmd[0]))
		reorganize(cmd);
}