/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:56:45 by                   #+#    #+#             */
/*   Updated: 2024/11/11 14:35:51 by babischa         ###   ########.fr       */
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
		//check_exit(2);
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
