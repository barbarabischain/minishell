/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:56:08 by babischa          #+#    #+#             */
/*   Updated: 2023/11/24 12:22:40 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strrchr() function returns a pointer to the last occurrence of the
character c in the string s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (ptr);
}
