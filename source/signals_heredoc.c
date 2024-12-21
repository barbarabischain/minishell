/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:19:28 by babischa          #+#    #+#             */
/*   Updated: 2024/12/21 12:20:04 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sigint_handler_heredoc(int signal)
{
	shell()->status = signal + 128;
	rl_on_new_line();
	rl_replace_line("", 0);
	close(0);
}

void	sigint_init_heredoc(void)
{
	signal(SIGINT, sigint_handler_heredoc);
}
