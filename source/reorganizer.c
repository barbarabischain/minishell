/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorganizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:49:17 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/09 18:32:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_size(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

static void	swap_token(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reorganize(char **cmd)
{
	int	size;
	int	i;
	int	j;

	size = get_size(cmd);
	printf("ueh: %d", size);
	i = 0;
	j = 1;
	while (j < size)
		swap_token(&cmd[i++], &cmd[j++]);
	i = 0;
	j = 1;
	while (j < size)
		swap_token(&cmd[i++], &cmd[j++]);
}
