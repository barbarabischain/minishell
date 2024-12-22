/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:53:56 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/22 14:13:33 by madias-m         ###   ########.fr       */
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

void	process_shell(void)
{
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
}

int	main(void)
{
	set_env_lst();
	get_shell_attr();
	while (1)
	{
		shell()->redisplay = 0;
		signals_init();
		if (receive_input() == -1)
		{
			complete_free();
			break ;
		}
		process_shell();
		cleanup_execution();
	}
}
