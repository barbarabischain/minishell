/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:09:10 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/25 20:18:40 by madias-m         ###   ########.fr       */
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

int get_next_redirect(char **cmd, int *init, char *target)
{
	int	target_len;

	target_len = ft_strlen(target);
	while (cmd[*init])
	{
		if (is_redirect(cmd[*init]) && ft_strncmp(cmd[*init], target, ft_strlen(target) + 1) == 0)
			return (*init);
		(*init)++;
	}
	return (0);
}

void	open_file(char **cmd, int i)
{
	int	red_num;

	red_num = is_redirect(cmd[i]);
	if (red_num == 2)
		set_out(cmd[i + 1]);
	else if (red_num == 3)
		set_append(cmd[i + 1]);
	else
		set_in(cmd[i + 1]);
}

void	erase_redirect_data(char **cmd, int init)
{
	if (cmd[init] && !is_redirect(cmd[init]))
		return ;
	while (cmd[init])
	{
		ft_bzero(cmd[init], ft_strlen(cmd[init]));
		init++;
	}
}

void	redirect(char **cmd)
{
	static char	*priority[4] = {"<", ">", ">>", "<<"};
	int			index;
	int 		i;
	
    while (is_redirect(cmd[0]))
		reorganize(cmd);
	index = 0;
	shell()->in_fd = 0;
	shell()->out_fd = 1;
	while (index < 4)
	{
		i = 0;
		while (get_next_redirect(cmd, &i, priority[index]) && !shell()->status)
			open_file(cmd, i++);
		index++;
	}
	i = 0;
	while (cmd[i] && !is_redirect(cmd[i]))
		i++;
	erase_redirect_data(cmd, i);
}