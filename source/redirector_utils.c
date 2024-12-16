/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:42:25 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/14 21:59:06 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_redirects(char **cmd)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (is_redirect(cmd[i++]))
			count++;
	}
	return (count);
}

int	contains_only_redirects(char **cmd, char **redirects)
{
	int	size_red;
	int	size_cmd;

	size_red = 0;
	size_cmd = 0;
	while (cmd[size_cmd])
		size_cmd++;
	while (redirects[size_red])
		size_red++;
	return (size_red == size_cmd);
}

static void	erase_redirect_data(char **cmd, int init)
{
	if (!init)
		return ;
	while (cmd[init])
	{
		free(cmd[init]);
		cmd[init] = NULL;
		init++;
	}
}

char	**fix_cmd(char **cmd)
{
	static int	i = 0;
	static int	something_else = 0;

	while (cmd[0][0] == -42)
		reorganize(cmd);
	while (cmd[i] && cmd[i][0] > 0)
		i++;
	while (cmd[i])
	{
		if (cmd[i++][0] != -42)
			something_else++;
	}
	while (something_else--)
	{
		i = 0;
		while (cmd[i] && cmd[i][0] > 0)
			i++;
		while (cmd[i] && cmd[i][0] == -42)
			reorganize(&cmd[i]);
	}
	i = 0;
	while (cmd[i] && cmd[i][0] > 0)
		i++;
	erase_redirect_data(cmd, i);
	return (cmd);
}
