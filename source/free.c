/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:36:44 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/22 14:14:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execution_clean(void)
{
	int	i;

	if (shell()->target_error)
	{
		free(shell()->target_error);
		shell()->target_error = NULL;
	}
	if (shell()->error_message)
	{
		(free(shell()->error_message));
		shell()->error_message = NULL;
	}
	free_list(&shell()->cmd_list);
	if (!shell()->cmd_array)
		return ;
	i = 0;
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
	cleanup_execution();
	rl_clear_history();
	free_env();
	free(shell());
}
