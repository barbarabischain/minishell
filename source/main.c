/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/10/24 14:33:40 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	set_env_lst();
	//print_matrix(sort_ascii(array_of_pointers(shell()->env_list)));
	while (1)
	{
		shell()->input = readline("prompt: ");
		add_history(shell()->input);
		check_exit();
		parse_input();
		tokenize();
		expand();
		execute();
		execution_free();
	}
}
