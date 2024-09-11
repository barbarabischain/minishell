/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:42:31 by babischa          #+#    #+#             */
/*   Updated: 2023/11/08 15:16:46 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  strdup() function returns a pointer to a new string which is a duplicate
of the string s.  Memory for the new string  is  obtained  with malloc(3), and
can be freed with free(3).*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
