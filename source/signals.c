/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:26:39 by babischa          #+#    #+#             */
/*   Updated: 2024/12/16 19:46:03 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		shell()->status = signum + 128;
	}
}

void	signal_init(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_execution_handler(int signum)
{
	if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		shell()->status = signum + 128;
	}
	else if (signum == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		shell()->status = signum + 128;
	}
}

void	signal_execution_init()
{
	signal(SIGINT, signal_execution_handler);
	signal(SIGQUIT, signal_execution_handler);
}
