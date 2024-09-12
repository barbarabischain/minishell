/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/09/12 17:43:53 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	function(char *str)
{
	char	**array;
	char	**path;
	char	*slashjoin;
	char	*fulljoin;
	int		i;

	i = 0;
	array = ft_split(str, ' ');
	path = ft_split(getenv("PATH"), ':');
	while (path[i])
	{
		slashjoin = ft_strjoin(*path, "/");
		fulljoin = ft_strjoin(slashjoin, *array);
		if (!access(slashjoin, F_OK))
			execve(slashjoin, array, __environ);
		free(slashjoin);
		free(fulljoin);
		i++;
	}
	free_array(path);
	free_array(array);
}

int	main(void)
{
	char	*str;
	pid_t	pid;

	while (1)
	{
		str = readline("prompt: ");
		add_history(str);
		if (!strcmp(str, "exit"))
		{
			rl_clear_history();
			free(str);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
			function(str);
		else
			wait(0);
		rl_clear_history();
		free(str);
	}
}
