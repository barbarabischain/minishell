/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/10/09 12:00:01 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_matrix(char **mtx)
{
	int	i;

	i = -1;
	while (mtx[++i])
		free(mtx[i]);
	free(mtx);
}

char	*find_path(char **paths, char *program)
{
	int		i;
	char	*half_join;
	char	*full_join;

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
	char **splitted_path;
	char **matrix;
	char *path;
	char **cmd_matrix;

	splitted_path = ft_split(lst_find(get_data()->env_list, "PATH")->value, ':');
	cmd_matrix = list_to_matrix(get_data()->cmd_list);
	cmd_matrix = remove_quotes(cmd_matrix);
	path = find_path(splitted_path, cmd_matrix[0]);
	if (!path)
	{
		printf("%s: command not found\n", cmd_matrix[0]);
		rl_clear_history();
		free_matrix(cmd_matrix);
		free_env();
		free_list(&get_data()->cmd_list);
		exit (127);
	}
	matrix = env_matrix(get_data()->env_list);
	execve(path, cmd_matrix, matrix);
	free(path);
	free_matrix(matrix);
}

int	main(void)
{
	char	*str;
	int		pid;

	set_env_lst();
	while (1)
	{
		str = readline("prompt: ");
		add_history(str);
		if (!ft_strncmp(str, "exit", 5))
		{
			rl_clear_history();
			free(str);
			free_env();
			exit(0);
		}
		token(str);
		pid = fork();
		if (pid == 0)
		{
			execute_command();
			free_env();
		}
		else
			wait(0);
		free_list(&get_data()->cmd_list);
		free(str);
	}
}
