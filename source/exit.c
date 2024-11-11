/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:40:07 by babischa          #+#    #+#             */
/*   Updated: 2024/11/11 16:26:05 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		get_status(int	status)
{
	static int	new_status;

	if (status != -42)
		new_status = status;
	return (new_status);
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

void	ft_exit(char **cmd_list)
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
	check_exit(n);
}

void	check_exit(int	status)
{
	int	n = status;
	n = 0;
	printf("status = %d", status);
	//free(shell()->input);
	complete_free();
	exit(0);
}
