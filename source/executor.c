/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:13 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/20 15:03:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*find_path(char **paths, char *program)
{
	int		i;
	char	*half_join;
	char	*full_join;

	if (program == NULL)
		return (NULL);
	if (ft_strchr(program, '/') && access(program, F_OK) == 0)
		return (ft_strdup(program));
	i = 0;
	half_join = ft_strjoin("/", program);
	while (paths[i])
	{
		full_join = ft_strjoin(paths[i++], half_join);
		if (access(full_join, F_OK) == 0)
		{
			free(half_join);
			return (full_join);
		}
		free(full_join);
	}
	free(half_join);
	return (0);
}

void	execute_bin(int i)
{
	char	**split_path;
	char	**envs;
	char	*path;

	split_path = ft_split(lst_find("PATH")->value, ':');
	path = find_path(split_path, shell()->cmd_array[i][0]);
	free_matrix(split_path);
	check_existence(path, i);
	check_executable(path, i);
	envs = env_matrix(shell()->env_list);
	execve(path, shell()->cmd_array[i], envs);
	free(path);
	free_matrix(envs);
	ft_printf_fd(2, \
	"minishell: %s: command not found\n", shell()->cmd_array[i][0]);
	shell()->status = 127;
	execute_exit();
}

static void	pipe_management(int pipes[2][2], int i)
{
	close(pipes[i % 2][0]);
	close(pipes[(i + 1) % 2][1]);
	if (i > 0)
		dup2(pipes[(i + 1) % 2][0], STDIN_FILENO);
	close(pipes[(i + 1) % 2][0]);
	if (i < shell()->cmd_array_size - 1)
		dup2(pipes[i % 2][1], STDOUT_FILENO);
	close(pipes[i % 2][1]);
}

static void	close_oposite_pipe(int pipes[2][2], int i)
{
	close(pipes[(i + 1) % 2][0]);
	close(pipes[(i + 1) % 2][1]);
}

void	execute(void)
{
	int		i;
	int		*pids;
	int		new_pipe[2][2];

	pids = ft_calloc(shell()->cmd_array_size + 1, sizeof(int));
	pipe(new_pipe[1]);
	i = 0;
	while (shell()->cmd_array[i])
	{
		pipe(new_pipe[i % 2]);
		pids[i] = fork();
		if (pids[i] == 0)
		{
			free(pids);
			pipe_management(new_pipe, i);
			redirect(shell()->cmd_array[i]);
			execute_command(i);
		}
		close_oposite_pipe(new_pipe, i++);
	}
	close_oposite_pipe(new_pipe, i);
	finalize_processes(pids);
}
