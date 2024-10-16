/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:48:49 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/16 12:35:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	*shell(void)
{
	static t_shell	*data;

	if (!data)
		data = ft_calloc(1, sizeof(t_shell));
	return (data);
}
