/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:13:47 by babischa          #+#    #+#             */
/*   Updated: 2023/11/11 14:10:14 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function ’f’ on each character of	the string passed as argument,
passing its index as first argument. Each character is passed by address to ’f’
to be modified if necessary.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
