/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/27 17:37:23 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_space_in_quotes(char *str, char quote)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == quote)
		{
			i++;
			while (str[i] && str[i] != quote)
			{
				if (str[i] == ' ')
					str[i] = -42;
				i++;
			}
			if (str[i] == quote)
				i++;
		}
		else
			i++;
	}
}

void	parse_input(void)
{
	shell()->input = put_space(shell()->input);
	parse_space_in_quotes(shell()->input, '\"');
	parse_space_in_quotes(shell()->input, '\'');
	tokenize();
}
