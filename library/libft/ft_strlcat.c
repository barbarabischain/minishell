/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:39:05 by babischa          #+#    #+#             */
/*   Updated: 2023/11/06 18:16:39 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strlcat() function concatenate strings. The strlcat() function appends the
 NUL-terminated string src to the end of dst.  It will append at most
 size - strlen(dst) - 1 bytes, NUL-terminating the result.
 Return the initial length of original dst plus the length of original src.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (n <= i)
		return (n + ft_strlen(src));
	ft_strlcpy(dst + i, src, n - i);
	return (i + ft_strlen(src));
}
