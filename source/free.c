/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:36:44 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/11 23:10:52 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execution_clean(void)
{
	int	i;

	i = 0;
	free_list(&shell()->cmd_list);
	if (!shell()->cmd_array)
		return ;
	while (shell()->cmd_array[i])
	{
		free_matrix(shell()->cmd_array[i]);
		shell()->cmd_array[i++] = NULL;
	}
	free(shell()->cmd_array);
	shell()->cmd_array = NULL;
}

void	complete_free(void)
{
	execution_clean();
	rl_clear_history();
	free_env();
	free(shell());
}
