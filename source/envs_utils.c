/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:04:31 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/04 12:39:15 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

	if (!env->value)
		return (ft_strdup(env->key));
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

void	free_env(void)
{
	t_env_list	*lst;
	t_env_list	*temp;

	lst = shell()->env_list;
	while (lst)
	{
		free(lst->key);
		free(lst->value);
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}
