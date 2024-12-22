/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:42 by babischa          #+#    #+#             */
/*   Updated: 2024/12/22 14:25:22 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env_list	**sort_ascii(t_env_list	**array)
{
	int			i;
	int			size;
	t_env_list	*temp;

	i = 0;
	size = env_lst_size(shell()->env_list);
	while (i < (size - 1))
	{
		if (strcmp(array[i]->key, array[i + 1]->key) > 0)
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (array);
}

int	env_lst_size(t_env_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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
