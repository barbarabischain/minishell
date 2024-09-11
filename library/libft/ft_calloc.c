/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:57:26 by babischa          #+#    #+#             */
/*   Updated: 2023/11/05 15:15:06 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  calloc()  function allocates memory for an array of nmemb elements of
size bytes each and returns a pointer to the allocated memory.b*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
