/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:40:07 by babischa          #+#    #+#             */
/*   Updated: 2024/10/16 14:31:48 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_exit(void)
{
	if (!ft_strncmp(shell()->input, "exit", 5))
	{
		rl_clear_history();
		free_env();
		free(shell()->input);
		free(shell());
		exit(0);
	}
}
