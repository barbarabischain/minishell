/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_envs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:44:29 by babischa          #+#    #+#             */
/*   Updated: 2024/10/15 13:58:33 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_env_key(char *env)
{
	int		size;
	char	*key;

	size = ft_strchr(env, '=') - env;
	key = ft_calloc(size + 2, 1);
	ft_strlcpy(key, env, size + 1);
	return (key);
}

char	*get_env_value(char *env)
{
	return (ft_strdup(ft_strchr(env, '=') + 1));
}

void	set_env_lst(void)
{
	t_env_list	*list;
	int			i;
	char		*key;
	char		*value;

	list = lst_new(get_env_key(*__environ), get_env_value(*__environ));
	i = 0;
	while (__environ[++i])
	{
		key = get_env_key(__environ[i]);
		value = get_env_value(__environ[i]);
		lst_add_ascii(list, key, value);
	}
	get_data()->env_list = list;
}

void	unset_env(t_env_list *lst, char *key)
{
	t_env_list	*found;
	t_env_list	*aux;

	found = lst_find(lst, key);
	if (!found)
		return ;
	while (lst->next != found)
		lst = lst->next;
	lst->next = NULL;
	aux = found->next;
	lst_add_next(lst, aux);
	free(found->key);
	free(found->value);
	free(found);
}
