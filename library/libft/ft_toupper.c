/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:29:21 by babischa          #+#    #+#             */
/*   Updated: 2023/11/06 11:38:55 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*If  c  is a lowercase letter, toupper() returns its uppercase equivalent,
if an uppercase representation exists in the current locale.  Otherwise,  
it  returns c. */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
