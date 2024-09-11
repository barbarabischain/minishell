/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:02:26 by babischa          #+#    #+#             */
/*   Updated: 2023/11/04 18:02:22 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether c is a 7-bit unsigned char value that fits into the ASCII 
character set.*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
