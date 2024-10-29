/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/10/29 14:00:58 by babischa         ###   ########.fr       */
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
		expand();
		execute();
		execution_free();
	}
}
