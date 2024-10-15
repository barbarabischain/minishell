/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:40:07 by babischa          #+#    #+#             */
/*   Updated: 2024/10/15 12:17:59 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_exit(char *str)
{
	if (!ft_strncmp(str, "exit", 5))
	{
		rl_clear_history();
		free(str);
		free_env();
		free(get_data());
		exit(0);
	}
}
