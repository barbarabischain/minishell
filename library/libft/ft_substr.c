/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:26:07 by babischa          #+#    #+#             */
/*   Updated: 2023/11/24 12:32:11 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a substring from the string ’s’. The
substring begins at index ’start’ and is of maximum size ’len’.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	lenstr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	lenstr = ft_strlen(s);
	if (lenstr - start < len)
		len = lenstr - start;
	if (start >= lenstr)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	while (i < len && start < lenstr)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
