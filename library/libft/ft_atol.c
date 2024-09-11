/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:55:53 by babischa          #+#    #+#             */
/*   Updated: 2024/08/18 13:56:16 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10;
		num = num + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
