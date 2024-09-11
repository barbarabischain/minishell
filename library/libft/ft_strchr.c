/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:09:30 by babischa          #+#    #+#             */
/*   Updated: 2023/11/24 12:35:44 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strchr() function returns a pointer to the first occurrence of the
character c in the string s.
The strchr() function returns a pointer to the matched character or  NULL
if  the character  is not found.  The terminating null byte is considered
part of the string, so that if c is specified as '\0', these functions
return a pointer to the terminator.*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if ((unsigned char)c == '\0')
		return (ptr);
	return (NULL);
}
