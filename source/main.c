/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:53:56 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/16 14:45:20 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int	g_signal;

static int	is_only_space(char *str)
{
	while (*str)
	{
		if (!((*str >= 9 && *str <= 13) || *str == 32))
			return (0);
		str++;
	}
	return (1);
}

static int	is_empty(char *str)
{
	return (str[0] == 0);
}

static int	receive_input(void)
{
	while (1)
	{
		shell()->input = readline("prompt: ");
		if (shell()->input == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			return (-1);
		}
		else if (!is_empty(shell()->input))
		{
			add_history(shell()->input);
			if (is_only_space(shell()->input))
				free(shell()->input);
			else
				return (0);
		}
		else
			free(shell()->input);
	}
	return (0);
}

int	main(void)
{
	set_env_lst();
	while (1)
	{
		g_signal = 143;
		signal_init();
		if (receive_input() == -1)
		{
			complete_free();
			break;
		}
		parse_input();
		heredoc(&shell()->cmd_list);
		expand();
		lexical_analyse();
		if (shell()->status == 0)
			execute();
		else
			printf("%s", shell()->error_message);
		execution_clean();
	}
	return (g_signal);
}
