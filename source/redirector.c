/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:09:10 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/22 22:22:13 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_redirect(char *token)
{
	if (!ft_strncmp(token, "<", 2))
		return (1);
	else if (!ft_strncmp(token, ">", 2))
		return (2);
	else if (!ft_strncmp(token, ">>", 3))
		return (3);
	else if (!ft_strncmp(token, "<<", 3))
		return (4);
	return (0);
}

int get_next_redirect(char **cmd, int init, char *target)
{
	int	target_len;

	target_len = ft_strlen(target);
	while (cmd[init])
	{
		if (is_redirect(cmd[init]) && ft_strncmp(cmd[init], target, ft_strlen(target) + 1))
			return (init);
		init++;
	}
	return (0);
}

static int	get_flags(char *redirect)
{
	int red_num;

	red_num = is_redirect(redirect);
	if (red_num == 1)
		return (O_RDONLY);
	else if (red_num == 2)
		return (O_WRONLY);
	else if (red_num == 3)
		return (O_APPEND);
	return (O_RDONLY);
}

int		open_file(char **cmd, int i)
{
	int fd;

	fd = open(cmd[i + 1], get_flags(cmd[i]));
	if (fd < 0)
		return (1);
	return (0);
}

void	redirect(char **cmd)
{
	static char	**priority = {"<", ">", ">>", "<<"};
	int			index;
	int 		i;
	
    while (is_redirect(cmd[0]))
		reorganize(cmd);
	index = 0;
	while (index < 4)
	{
		i = 0;
		while (get_next_redirect(cmd, i, priority[index]) && !shell()->status)
			shell()->status = open_file(cmd, i++);
		index++;
	}

	
}