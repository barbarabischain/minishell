/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:11:50 by babischa          #+#    #+#             */
/*   Updated: 2023/11/10 11:21:06 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > start && ft_strchr(set, s1[i]))
		i--;
	end = i;
	new = ft_substr(s1, start, end - start + 1);
	return (new);
}
