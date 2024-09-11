/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/09/11 17:43:00 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	function(char *str)
{
	char	**array;
	char	**path;
	char	*join;

	array = ft_split(str, ' ');
	path = ft_split(getenv("PATH"), ':');
	while(*path)
	{
		join = ft_strjoin(*path, "/");
		join = ft_strjoin(join, *array);
		if (!access(join, F_OK))
			execve(join, array, NULL);
		path++;
	}
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
		rl_clear_history();
		free(str);
	}
}
