/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:18:40 by babischa          #+#    #+#             */
/*   Updated: 2024/11/04 18:26:54 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	token_type(char *str)
{
	if (!ft_strncmp(str, "|", 2))
		return (PIPE);
	else if (!ft_strncmp(str, "<", 2))
		return (IN_R);
	else if (!ft_strncmp(str, ">", 2))
		return (OUT_R);
	else if (!ft_strncmp(str, "<<", 3))
		return (HEREDOC);
	else if (!ft_strncmp(str, ">>", 3))
		return (APPEND);
	return (WORD);
}

void	print_type(char **str)
{
	int	type;

	while (*str)
	{
		type = token_type(*str);
		printf("command: %s -- type: %d\n", *str, type);
		str++;
	}
}
