/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:48:49 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/14 16:46:03 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	*get_data(void)
{
	static t_data	*data;

	if (!data)
		data = ft_calloc(1, sizeof(t_data));
	return (data);
}
