/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:39:54 by babischa          #+#    #+#             */
/*   Updated: 2023/11/06 11:40:27 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* If c is an uppercase letter, tolower() returns its lowercase equivalent,
if  a lowercase  representation  exists in the current locale.  Otherwise,
it returns c.*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
