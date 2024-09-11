/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:23:24 by babischa          #+#    #+#             */
/*   Updated: 2024/08/18 16:46:16 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end with a
NULL pointer.*/

#include "libft.h"
#include <stdlib.h>

char	**ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
	return (NULL);
}

char	**ft_allocation(char const *s, char **array, char c)
{
	char	*start;
	char	*end;
	size_t	i;

	start = (char *)s;
	end = (char *)s;
	i = 0;
	while (*start)
	{
		while (*start == c && *start)
			start++;
		end = start;
		while (*end != c && *end)
			end++;
		if (end > start)
		{
			array[i] = ft_calloc(end - start + 1, sizeof(char));
			if (!array[i])
				return (ft_free(array));
			ft_strlcpy(array[i], start, end - start + 1);
			i++;
		}
		start = end;
	}
	return (array);
}

size_t	ft_count_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;

	if (!s)
		return (0);
	i = ft_count_word(s, c);
	array = ft_calloc(i + 1, sizeof(char *));
	if (!array)
		return (0);
	return (ft_allocation(s, array, c));
}
