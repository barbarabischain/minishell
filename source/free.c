/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:36:44 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/28 11:52:46 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execution_clean(void)
{
	free_list(&shell()->cmd_list);
}

void	complete_free(void)
{
	execution_clean();
	rl_clear_history();
	free_env();
	free(shell());
}
