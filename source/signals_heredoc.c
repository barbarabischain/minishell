/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:41:32 by babischa          #+#    #+#             */
/*   Updated: 2024/12/16 16:31:41 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	signal_heredoc_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_signal = SIGINT;
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_heredoc_init(void)
{
	signal(SIGINT, signal_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
}
