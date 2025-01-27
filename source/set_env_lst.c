/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:56:28 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/22 15:08:19 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_key(char *env)
{
	int		size;
	char	*key;

	if (ft_strchr(env, '='))
	{
		size = ft_strchr(env, '=') - env;
		key = ft_calloc(size + 2, 1);
		ft_strlcpy(key, env, size + 1);
	}
	else
		key = ft_strdup(env);
	return (key);
}

char	*get_value(char *env)
{
	return (ft_strdup(ft_strchr(env, '=') + 1));
}

void	set_env_lst(void)
{
	t_env_list	*list;
	int			i;

	list = lst_new(get_key(*__environ), get_value(*__environ));
	i = 0;
	while (__environ[++i])
		lst_add_ascii(list, get_key(__environ[i]), get_value(__environ[i]));
	shell()->env_list = list;
}

void	export_env(t_env_list *lst, char *key, char *value)
{
	t_env_list	*found;

	found = lst_find(key);
	if (!found)
		lst_add_ascii(lst, key, value);
	else
	{
		free(found->key);
		free(found->value);
		found->key = key;
		found->value = value;
	}
}

void	unset_env(t_env_list *lst, char *key)
{
	t_env_list	*found;
	t_env_list	*aux;

	found = lst_find(key);
	if (!found)
		return ;
	while (lst->next && lst->next != found)
		lst = lst->next;
	lst->next = NULL;
	aux = found->next;
	lst_add_next(lst, aux);
	free(found->key);
	free(found->value);
	free(found);
}
