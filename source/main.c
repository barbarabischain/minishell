/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/07 22:48:34 by madias-m         ###   ########.fr       */
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

static void	receive_input(void)
{
	while (1)
	{
		shell()->input = readline("prompt: ");
		if (!is_empty(shell()->input))
		{
			add_history(shell()->input);
			if (is_only_space(shell()->input))
				free(shell()->input);
			else
				return ;
		}
		else
			free(shell()->input);
	}
	
}

int	main(void)
{
	set_env_lst();
	while (1)
	{
		receive_input();
		check_exit();
		parse_input();
		tokenize();
		lexical_analyse();
		if (!shell()->status)
		{
			expand();
			execute();
		}
		else
			printf("test: syntax error near unexpected token: {token}\n");
		execution_clean();
	}
}
