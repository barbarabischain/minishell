/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:09:10 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/08 11:13:08 by madias-m         ###   ########.fr       */
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

int get_next_redirect(char **cmd, int *init)
{
	while (cmd[*init])
	{
		if (is_redirect(cmd[*init]))
			return (*init + 1);
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
		free(cmd[init]);
		cmd[init] = NULL;
		init++;
	}
}

void	redirect(char **cmd)
{
	int 		i;
	
	shell()->in_fd = 0;
	shell()->out_fd = 1;
	i = 0;
	while (get_next_redirect(cmd, &i) && !shell()->status)
		open_file(cmd, i++);
    while (is_redirect(cmd[0]))
		reorganize(cmd);
	i = 0;
	while (cmd[i] && !is_redirect(cmd[i]))
		i++;
	erase_redirect_data(cmd, i);
}