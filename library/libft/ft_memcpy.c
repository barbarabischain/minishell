/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:28:21 by babischa          #+#    #+#             */
/*   Updated: 2023/11/24 12:03:41 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The memcpy() function copies n bytes from memory area src to memory
area dest.The memory areas must not overlap.  Use memmove(3) if the memory
areas do overlap.
The memcpy() function returns a pointer to dest.*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
