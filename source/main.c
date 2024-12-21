/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:53:56 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/21 12:43:13 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	struct termios	fd;
	int				old_fd;

	set_env_lst();
	fd = (struct termios){0};
	tcgetattr(STDIN_FILENO, &fd);
	old_fd = dup(STDIN_FILENO);
	while (1)
	{
		shell()->redisplay = 0;
		signals_init();
		if (receive_input() == -1)
		{
			complete_free();
			break ;
		}
		parse_input();
		sigint_init_heredoc();
		if (heredoc(&shell()->cmd_list))
		{
			signals_init();
			expand();
			lexical_analyse();
			if (shell()->status == 0)
			{
				shell()->redisplay = 1;
				build_command_array();
				if (!exec_single_builtin())
					execute();
			}
		}
		execution_clean();
		tcsetattr(STDIN_FILENO, TCSANOW, &fd);
		dup2(old_fd, STDIN_FILENO);
	}
}
