/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/10/01 00:11:02 by madias-m         ###   ########.fr       */
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

	if (ft_strchr(program, '/'))
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

void	execute_command(char *cmd, t_data *data)
{
	char **splitted_cmd;
	char **splitted_path;
	char **matrix;
	char *path;

	splitted_cmd = ft_split(cmd, ' ');
	splitted_path = ft_split(lst_find(data->env_list, "PATH")->value, ':');
	path = find_path(splitted_path, splitted_cmd[0]);
	if (!path)
	{
		printf("%s: command not found\n", splitted_cmd[0]);
		free_matrix(splitted_cmd);
		free_env(data->env_list);
		free_list(&data->cmd_list);
		exit (127);
	}
	matrix = env_matrix(data->env_list);
	execve(path, splitted_cmd, matrix);
	free(path);
	free_matrix(matrix);
	free_matrix(splitted_cmd);
}

int	main(void)
{
	t_data	data;
	char	*str;
	int		pid;

	set_env_lst(&data);
	while (1)
	{
		str = readline("prompt: ");
		add_history(str);
		if (!ft_strncmp(str, "exit", 5))
		{
			rl_clear_history();
			free(str);
			free_env(data.env_list);
			exit(0);
		}
		token(str, &data);
		pid = fork();
		if (pid == 0)
		{
			execute_command(str, &data);
			free_env(data.env_list);
		}
		else
			wait(0);
		free_list(&data.cmd_list);
		free(str);
	}
}
