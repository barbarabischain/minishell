/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:13 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/02 14:19:55 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*find_path(char **paths, char *program)
{
	int		i;
	char	*half_join;
	char	*full_join;

	if (program == NULL)
	{
		free_matrix(paths);
		return (NULL);
	}
	if (ft_strchr(program, '/') && access(program, F_OK) == 0)
	{
		free_matrix(paths);
		return (ft_strdup(program));
	}
	i = 0;
	half_join = ft_strjoin("/", program);
	while (paths[i])
	{
		full_join = ft_strjoin(paths[i++], half_join);
		if (access(full_join, F_OK) == 0)
		{
			free(half_join);
			free_matrix(paths);
			return (full_join);
		}
		free(full_join);
	}
	free(half_join);
	free_matrix(paths);
	return (0);
}

static void	execute_command(int i)
{
	char	**split_path;
	char	**envs;
	char	*path;

	split_path = ft_split(lst_find("PATH")->value, ':');
	path = find_path(split_path, shell()->cmd_array[i][0]);
	if (!path)
	{
		if (shell()->cmd_array[i][0])
			printf("%s: command not found\n", shell()->cmd_array[i][0]);
		complete_free();
		exit (127);
	}
	envs = env_matrix(shell()->env_list);
	execve(path, shell()->cmd_array[i], envs);
	free(path);
	free_matrix(envs);
	complete_free();
}

void	execute(void)
{
	int		i;
	int		pid;

	build_command_array();
	i = 0;
	if (shell()->cmd_array_size == 1 && !(ft_strncmp(shell()->cmd_array[0][0], "exit", 5)))
		check_exit(shell()->cmd_array[i]);
	while (shell()->cmd_array[i])
	{
		pid = fork();
		if (pid == 0)
		{
			if (is_builtin(shell()->cmd_array[i]))
				execute_builtins(shell()->cmd_array[i]);
			else
			{
				redirect(shell()->cmd_array[i]);
				execute_command(i);
			}
		}
		else
			wait(0);
		i++;
	}
}
