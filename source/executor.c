/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:13 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/10 18:37:16 by babischa         ###   ########.fr       */
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

int	**create_pipes(void)
{
	int	pipes_qtd;
	int	i;
	int **pipes;

	pipes_qtd = shell()->cmd_array_size;
	i = 0;
	pipes = ft_calloc(pipes_qtd, sizeof(void *));
	while (i < pipes_qtd)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		pipe(pipes[i]);
		i++;
	}
	return (pipes);
}

void	execute(void)
{
	int		i;
	int		*pids;
	int		**pipes;

	build_command_array();
	i = 0;
	if (shell()->cmd_array_size == 1 && !(ft_strncmp(shell()->cmd_array[0][0], "exit", 5)))
		check_exit(shell()->cmd_array[0]);
	pipes = create_pipes();
	pids = ft_calloc(shell()->cmd_array_size, sizeof(int));
	while (shell()->cmd_array[i])
	{
		pids[i] = fork();
		signal_execution_init(pids[i]);
		if (pids[i] == 0)
		{
			close(pipes[i][0]);
			if (i > 0 && shell()->in_fd == 0)
				dup2(pipes[i - 1][0], STDIN_FILENO);
			if (i < shell()->cmd_array_size - 1) // meio
				dup2(pipes[i][1], STDOUT_FILENO);
			redirect(shell()->cmd_array[i]);
			close(pipes[i][1]);
			execute_command(i);
		}
		else
		{
			if (pipes[i])
				close(pipes[i][1]);
			if (i > 0)
				close(pipes[i -1][0]);
			i++;
		}
	}
	i = 0;
	while (i < shell()->cmd_array_size - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	i = 0;
	while (pids[i])
	{
		waitpid(pids[i], &shell()->status, 0);
		shell()->status = (WEXITSTATUS(shell()->status));
		i++;
	}
}
