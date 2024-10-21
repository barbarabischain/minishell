/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:56:28 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/17 18:11:06 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_key(char *env)
{
	int		size;
	char	*key;

	size = ft_strchr(env, '=') - env;
	key = ft_calloc(size + 2, 1);
	ft_strlcpy(key, env, size + 1);
	return (key);
}

static char	*get_value(char *env)
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

	found = lst_find(lst, key);
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
