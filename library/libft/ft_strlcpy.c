/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:31:07 by babischa          #+#    #+#             */
/*   Updated: 2023/11/06 18:17:25 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strlcpy() function copies up to size - 1 characters from the NUL-
terminated string src to dst, NUL-terminating the result. The strlcpy() and
strlcat() functions return the total length of thestring they tried to create.
For strlcpy() that means the length of src.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
