/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:40:07 by babischa          #+#    #+#             */
/*   Updated: 2024/12/02 11:40:50 by babischa         ###   ########.fr       */
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

void	execute_exit(void)
{
	complete_free();
	//free(shell()->input);
	exit(shell()->status);
}

void	exit_handler(char **cmd_list)
{
	int	i;

	i = 1;
	if (!cmd_list[i])
		shell()->status = 0;
	else if (cmd_list[2])
	{
		free_matrix(cmd_list);
		printf("bash: exit: too many arguments\n");
		shell()->status = 1;
		return ;
	}
	else if(!check_digit(cmd_list[i]))
	{
		printf("bash: exit: %s: numeric argument required\n", cmd_list[i]);
		shell()->status = 2;
	}
	else
		shell()->status = ft_atoi(cmd_list[i]) % 256;
	free_matrix(cmd_list);
	execute_exit();
}


void	check_exit(void)
{
		exit_handler(remove_quotes(list_to_matrix(shell()->cmd_list)));
		//exit_handler(shell()->cmd_array);
}
