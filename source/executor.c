/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:13 by madias-m          #+#    #+#             */
/*   Updated: 2024/11/11 16:15:47 by babischa         ###   ########.fr       */
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

void	execute_command(void)
{
	char	**split_path;
	char	**matrix;
	char	*path;
	char	**cmd_matrix;

	split_path = ft_split(lst_find(shell()->env_list, "PATH")->value, ':');
	cmd_matrix = remove_quotes(list_to_matrix(shell()->cmd_list));
	path = find_path(split_path, cmd_matrix[0]);
	if (!path)
	{
		if (cmd_matrix[0])
			printf("%s: command not found\n", cmd_matrix[0]);
		free_matrix(cmd_matrix);
		complete_free();
		exit (127);
	}
	matrix = env_matrix(shell()->env_list);
	//execve(path, cmd_matrix, matrix);
	free(path);
	free_matrix(matrix);
	complete_free();
}

void	execute(void)
{
	int		pid;

	//pid = fork();
	pid = 0;
	if (pid == 0)
	{
		if (is_builtin(shell()->cmd_list))
			execute_builtins(shell()->cmd_list);
		else
			execute_command();
	}
	else
		wait(0);
}
