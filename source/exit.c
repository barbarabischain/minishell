/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:40:07 by babischa          #+#    #+#             */
/*   Updated: 2024/11/12 16:09:58 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		exit_status(int	new_status)
{
	shell()->status = new_status;
	printf("status: %d\n", new_status);
}

int	check_digit(char *arg)
{
	while (*arg)
	{
		if(!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

void	check_exit(char **cmd_list)
{
	int	i;
	int	n;

	i = 1;
	if (!cmd_list[i])
		n = 0;
	else if (cmd_list[2])
	{
		free_matrix(cmd_list);
		printf("bash: exit: too many arguments\n");
		return ;
	}
	else if(!check_digit(cmd_list[i]))
	{
		printf("bash: exit: %s: numeric argument required\n", cmd_list[i]);
		n = 2;
	}
	else
		n = ft_atoi(cmd_list[i]) % 256;
	free_matrix(cmd_list);
	execute_exit(n);
}

void	execute_exit(int	status)
{
	int	n = status;
	n = 0;
	printf("status = %d", status);
	//free(shell()->input);
	complete_free();
	exit(0);
}
