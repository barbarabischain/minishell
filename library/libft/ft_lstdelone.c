/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:51:56 by babischa          #+#    #+#             */
/*   Updated: 2023/11/23 14:13:56 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Takes as a parameter a node and frees the memory of the node’s content using
the function ’del’ given as a parameter and free the node. The memory of ’next’
must not be freed.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
}
