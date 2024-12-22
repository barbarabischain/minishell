/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:40:07 by babischa          #+#    #+#             */
/*   Updated: 2024/12/22 14:21:55 by madias-m         ###   ########.fr       */
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

	status = shell()->status;
	close(shell()->in_bu);
	close(shell()->out_bu);
	complete_free();
	exit(status);
}

void	check_exit(char **cmd_list)
{
	int	i;

	i = 1;
	if (!cmd_list[i])
		shell()->status = 0;
	else if (cmd_list[2])
	{
		ft_printf_fd(2, "bash: exit: too many arguments\n");
		shell()->status = 1;
		return ;
	}
	else if (!check_digit(cmd_list[i]))
	{
		ft_printf_fd(2, "bash: exit: %s: numeric argument required\n", \
		cmd_list[i]);
		shell()->status = 2;
	}
	else
		shell()->status = ft_atoi(cmd_list[i]) % 256;
	execute_exit();
}
