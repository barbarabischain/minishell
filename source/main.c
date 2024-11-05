/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/04 21:47:14 by madias-m         ###   ########.fr       */
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
		else
			printf("%s", shell()->error_message);
		execution_clean();
	}
}
