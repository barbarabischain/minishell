/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:18:40 by babischa          #+#    #+#             */
/*   Updated: 2024/10/15 12:35:03 by babischa         ###   ########.fr       */
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
	if (!strcmp(str, "|"))
		return (1);
	else if ((!strcmp(str, "<")) || (!strcmp(str, ">"))
		|| (!strcmp(str, "<<")) || (!strcmp(str, ">>")))
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
