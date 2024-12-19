/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:13 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/16 19:54:35 by babischa         ###   ########.fr       */
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
			ft_printf_fd(2 ,"%s: command not found\n", shell()->cmd_array[i][0]);
		shell()->status = 127;
		execute_exit();
	}
	envs = env_matrix(shell()->env_list);
	execve(path, shell()->cmd_array[i], envs);
	free(path);
	free_matrix(envs);
	execute_exit();
}

void	execute(void)
{
	int		i;
	int		*pids;
	int		new_pipe[2];

	build_command_array();
	i = 0;
	if (shell()->cmd_array_size == 1 && !(ft_strncmp(shell()->cmd_array[0][0], "exit", 5)))
		check_exit(shell()->cmd_array[0]);
	pids = ft_calloc(shell()->cmd_array_size + 1, sizeof(int));
	pipe(new_pipe);
	signal_execution_init();
	while (shell()->cmd_array[i])
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			free(pids);
			if (i > 0)
				dup2(new_pipe[0], STDIN_FILENO);
			close(new_pipe[0]);
			if (i < shell()->cmd_array_size - 1)
				dup2(new_pipe[1], STDOUT_FILENO);
			close(new_pipe[1]);
			redirect(shell()->cmd_array[i]);
			execute_command(i);
		}
		i++;
	}
	close(new_pipe[0]);
	close(new_pipe[1]);
	i = 0;
	while (pids[i])
	{
		waitpid(pids[i], &shell()->status, 0);
		shell()->status = (WEXITSTATUS(shell()->status));
		i++;
	}
	free(pids);
}
