/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:09:05 by babischa          #+#    #+#             */
/*   Updated: 2023/11/10 11:20:12 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_len(nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = len;
	if (n < 0)
		nbr = -nbr;
	while (nbr >= 0 && i > 0)
	{
		i--;
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
