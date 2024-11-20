/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:40:16 by babischa          #+#    #+#             */
/*   Updated: 2024/11/20 17:40:28 by babischa         ###   ########.fr       */
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
		identifie_files();
		if (shell()->status == 0)
		{
			expand();
			execute();
		}
		else
			printf("%s", shell()->error_message);
		execution_clean();
	}
}
