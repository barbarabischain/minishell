/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/09/10 17:22:58 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(void)
{
	char *str;

	while (1)
	{
		str = readline("prompt: ");
		add_history(str);
		if (!strcmp(str, "exit"))
		{
			rl_clear_history();
			free(str);
			exit(0);
		}
		rl_clear_history();
		free(str);
	}
}
