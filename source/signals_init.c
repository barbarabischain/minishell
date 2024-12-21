/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:41:10 by babischa          #+#    #+#             */
/*   Updated: 2024/12/21 11:44:33 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sigint_handler(int sigint)
{
	shell()->status = 128 + sigint;
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (shell()->config == 0)
		rl_redisplay();
}

void sigquit_handler(int sigquit)
{
	shell()->status = sigquit + 128;
	ft_putstr_fd("Quit (core dumped)\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void sigquit_init(void)
{
	signal(SIGQUIT, sigquit_handler);
}

void sigint_handler_heredoc(int signal)
{
	shell()->status = signal + 128;
	rl_on_new_line();
	rl_replace_line("", 0);
	close(0);
}

void sigint_init_heredoc(void)
{
	signal(SIGINT, sigint_handler_heredoc);
}

void signals_init(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
