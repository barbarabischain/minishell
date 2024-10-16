/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/10/16 12:45:27 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	char	**split_path;
	char	**matrix;
	char	*path;
	char	**cmd_matrix;

	split_path = ft_split(lst_find(shell()->env_list, "PATH")->value, ':');
	cmd_matrix = list_to_matrix(shell()->cmd_list);
	cmd_matrix = remove_quotes(cmd_matrix);
	path = find_path(split_path, cmd_matrix[0]);
	if (!path)
	{
		printf("%s: command not found\n", cmd_matrix[0]);
		rl_clear_history();
		free_matrix(cmd_matrix);
		free_env();
		free_list(&shell()->cmd_list);
		free(shell());
		exit (127);
	}
	matrix = env_matrix(shell()->env_list);
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
		check_exit(str);
		token(str);
		pid = fork();
		if (pid == 0)
		{
			execute_command();
			free_env();
			free(shell());
		}
		else
			wait(0);
		free_list(&shell()->cmd_list);
	}
}
