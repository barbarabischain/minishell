/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:15:30 by babischa          #+#    #+#             */
/*   Updated: 2023/11/07 19:11:55 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  strlen() function calculates the length of the string pointed to by s,
 excluding the terminating null byte ('\0').
The strlen() function returns the number of bytes in the string pointed
 to by s.*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
