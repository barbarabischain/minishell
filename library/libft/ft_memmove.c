/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:10:21 by babischa          #+#    #+#             */
/*   Updated: 2023/11/24 14:29:01 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  memmove()  function  copies  n bytes from memory area src to memory
area dest.The memory areas may overlap: copying takes place as though the
bytes  in  src  are first  copied  into  a  temporary  array that does not
overlap src or dest, and the bytes are then copied from the temporary array
to dest. The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!src && !dest)
		return (NULL);
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (s > d)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
