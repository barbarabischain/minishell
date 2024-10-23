/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:42 by babischa          #+#    #+#             */
/*   Updated: 2024/10/23 12:34:13 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	env_lst_size(t_env_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_env_list	**array_of_pointers(t_env_list	*lst)
{
	t_env_list	*tmp;
	t_env_list	**array;
	int			i;

	i = 0;
	tmp = lst;
	array = ft_calloc(env_lst_size(lst) + 1, sizeof(t_env_list));
	while (tmp)
	{
		array[i] = tmp;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
