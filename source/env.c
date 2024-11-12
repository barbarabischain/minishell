/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:38:31 by babischa          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:52 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env(char **cmd_list)
{
	int	i;

	i = 1;
	while (cmd_list[i])
	{
		if (!is_valid_name(cmd_list[i]) || !ft_strchr(cmd_list[i], '='))
		{
			printf("env: syntax error\n");
			free_matrix(cmd_list);
			exit_status(2);
			return ;
		}
		i++;
	}
	i = 1;
	print_env(shell()->env_list);
	while (cmd_list[i])
		printf("%s\n", cmd_list[i++]);
	free_matrix(cmd_list);
	exit_status(0);
}
