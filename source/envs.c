/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:56:28 by madias-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:45:53 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	free_env(void)
{
	t_env_list	*lst;
	t_env_list	*temp;

	lst = get_data()->env_list;
	while (lst)
	{
		free(lst->key);
		free(lst->value);
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

static int	count_envs(t_env_list *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	*join_env(t_env_list *env)
{
	char	*half;
	char	*full;

	half = ft_strjoin(env->key, "=");
	full = ft_strjoin(half, env->value);
	free(half);
	return (full);
}

char	**env_matrix(t_env_list *env)
{
	int		size;
	int		i;
	char	**matrix;

	size = count_envs(env);
	matrix = ft_calloc(size + 1, sizeof(void *));
	i = 0;
	while (i < size)
	{
		matrix[i++] = join_env(env);
		env = env->next;
	}
	return (matrix);
}
