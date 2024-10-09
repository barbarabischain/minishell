/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:48:49 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/09 12:02:52 by madias-m         ###   ########.fr       */
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