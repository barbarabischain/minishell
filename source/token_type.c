/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:18:40 by babischa          #+#    #+#             */
/*   Updated: 2024/10/18 18:16:45 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:18:40 by babischa          #+#    #+#             */
/*   Updated: 2024/10/15 12:32:14 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	token_type(char *str)
{
	if (!ft_strncmp(str, "|", 1))
		return (1);
	else if ((!ft_strncmp(str, "<", 1)) || (!ft_strncmp(str, ">", 1))
		|| (!ft_strncmp(str, "<<", 2)) || (!ft_strncmp(str, ">>", 2)))
		return (2);
	return (0);
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
