/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:40:07 by babischa          #+#    #+#             */
/*   Updated: 2024/12/16 15:49:56 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_digit(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

void	execute_exit(void)
{
	int	status;

	status = g_signal;
	complete_free();
	exit(status);
}

void	check_exit(char **cmd_list)
{
	int	i;

	i = 1;
	if (!cmd_list[i])
		g_signal = 0;
	else if (cmd_list[2])
	{
		printf("bash: exit: too many arguments\n");
		g_signal = 1;
		return ;
	}
	else if (!check_digit(cmd_list[i]))
	{
		printf("bash: exit: %s: numeric argument required\n", cmd_list[i]);
		g_signal = 2;
	}
	else
		g_signal = ft_atoi(cmd_list[i]) % 256;
	execute_exit();
}
