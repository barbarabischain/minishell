/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:42:25 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/09 15:44:57 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		count_redirects(char **cmd)
{
	int count;
	int i;
	
	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (is_redirect(cmd[i++]))
			count++;
	}
	return (count);
}

char	**build_redirects_matrix(char **cmd)
{
	int		count;
	char	**redirects_matrix;
	int		i;

	count = count_redirects(cmd);
	redirects_matrix = ft_calloc(count * 2 + 1, sizeof(void *));
	i = 0;
	count = 0;
	while (get_next_redirect(cmd, &i))
	{
		redirects_matrix[count] = ft_strdup(cmd[i]);
		redirects_matrix[count + 1] = ft_strdup(cmd[i + 1]);
		cmd[i][0] = -42;
		cmd[i + 1][0] = -42;
		count += 2;
		i++;
	}
	return (redirects_matrix);
}
