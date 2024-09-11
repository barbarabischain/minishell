/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:16:56 by babischa          #+#    #+#             */
/*   Updated: 2023/11/20 15:21:47 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  memcmp()  function  compares  the first n bytes (each interpreted as 
unsigned char) of the memory areas s1 and s2.  The memcmp() function returns an
integer less than, equal to, or greater than zero if  the  first n bytes of s1
is found, respectively, to be less than, to match, or be greater than the
first n bytes of s2.
if n = 0 the return value is 0;
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n - 1 && ptr1[i] == ptr2[i])
		i++;
	return (ptr1[i] - ptr2[i]);
}
