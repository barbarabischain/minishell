/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:34:18 by babischa          #+#    #+#             */
/*   Updated: 2023/11/23 14:13:48 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Deletes and frees the given node and every successor of that node, using the
function ’del’ and free(3). Finally, the pointer to the list must be set to
NULL.*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (lst && del)
	{
		current = *lst;
		while (current != NULL)
		{
			tmp = current;
			current = current->next;
			ft_lstdelone(tmp, del);
		}
		*lst = NULL;
	}
}
