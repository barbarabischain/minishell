/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/11/04 19:02:51 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{	
	set_env_lst();
	while (1)
	{
		shell()->input = readline("prompt: ");
		add_history(shell()->input);
		check_exit();
		parse_input();
		tokenize();
		lexical_analyse();
		identifie_files();
		check_files();
		if (shell()->status == 0)
		{
			expand();
			execute();
		}
		else if (shell()->status == 2)
			printf("test: syntax error near unexpected token: {token}\n");
		else if (shell()->status == 1)
			printf("File error\n");
		execution_clean();
	}
}
