/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:49:46 by babischa          #+#    #+#             */
/*   Updated: 2023/11/12 16:06:44 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The bzero() function erases the data in the n bytes of the memory starting
at the location pointed to by s, by writing zeros (bytes  containing'\0') to 
that area.*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
