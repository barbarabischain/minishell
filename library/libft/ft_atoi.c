/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:13:21 by babischa          #+#    #+#             */
/*   Updated: 2023/11/24 14:43:29 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  atoi() function converts the initial portion of the string pointed to by
nptr to int.*/

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r') || (c == '\v')
		|| (c == '\t'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

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
