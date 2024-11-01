/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:54:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/31 17:33:20 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env_list	*lst_new(char *key, char *value)
{
	t_env_list	*lst;

	lst = ft_calloc(1, sizeof(t_env_list));
	lst->key = key;
	lst->value = value;
	return (lst);
}

t_env_list	*lst_add_next(t_env_list *lst, t_env_list *next)
{
	lst->next = next;
	return (lst);
}

void	lst_add_ascii(t_env_list *lst, char *key, char *value)
{
	while (lst->next && ft_strncmp(lst->key, key, ft_strlen(key)) > 0)
	{
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	if (lst->next)
		lst->next = lst_add_next(lst_new(key, value), lst->next);
	else
		lst->next = lst_new(key, value);
}

t_env_list	*lst_find(t_env_list *lst, char *key)
{
	while (lst)
	{
		if (!ft_strncmp(lst->key, key, ft_strlen(key)))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	print_env(t_env_list *lst)
{
	while (lst)
	{
		printf("%s=%s\n", lst->key, lst->value);
		lst = lst->next;
	}
}
