/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/10/02 14:03:51 by babischa         ###   ########.fr       */
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

void	execute_command(t_data *data)
{
	//char **splitted_cmd;
	char **splitted_path;
	char **matrix;
	char *path;
	char **cmd_matrix;

	//splitted_cmd = ft_split(cmd, ' ');
	splitted_path = ft_split(lst_find(data->env_list, "PATH")->value, ':');
	cmd_matrix = list_to_matrix(data->cmd_list);
	cmd_matrix = remove_quotes(cmd_matrix);
	path = find_path(splitted_path,cmd_matrix[0]);
	if (!path)
	{
		printf("%s: command not found\n", data->cmd_list->value);
		free_matrix(cmd_matrix);
		free_env(data->env_list);
		free_list(&data->cmd_list);
		exit (127);
	}
	matrix = env_matrix(data->env_list);
	execve(path, cmd_matrix, matrix);
	free(path);
	free_matrix(matrix);
	//free_matrix(splitted_cmd);
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
			execute_command(&data);
			free_env(data.env_list);
		}
		else
			wait(0);
		free_list(&data.cmd_list);
		free(str);
	}
}
