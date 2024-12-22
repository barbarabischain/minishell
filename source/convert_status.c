/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:54:13 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/22 13:55:39 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	convert_status(void)
{
	int	status;

	status = shell()->status;
	if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == SIGQUIT)
			shell()->status = 131;
		else if (status == SIGINT)
			shell()->status = 130;
	}
	else if (WIFEXITED(status))
		shell()->status = WEXITSTATUS(status);
	else
		shell()->status = 0;
}
