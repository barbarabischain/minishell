/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:19:51 by babischa          #+#    #+#             */
/*   Updated: 2023/11/05 14:59:17 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>*/
/*The  memset()  function  fills  the  first  n  bytes of the memory area
pointed to by s with the constant byte c. The memset() function returns a
pointer to the memory area s.*/
/*The C library function void *memset(void *str, int c, size_t n) copies the 
character c (an unsigned char) to the first n characters of the string pointed
to, by the argument str.*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}	
	return (s);
}
