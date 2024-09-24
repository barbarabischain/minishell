/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:38:39 by babischa          #+#    #+#             */
/*   Updated: 2024/09/24 18:08:05 by madias-m         ###   ########.fr       */
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
	char *path;

	splitted_cmd = ft_split(cmd, ' ');
	splitted_path = ft_split(lst_find(data->env_list, "PATH")->value, ':');
	path = find_path(splitted_path, splitted_cmd[0]);
	if (!path)
		exit (127);
	execve(path, splitted_cmd, __environ);
	free(path);
	free_matrix(splitted_path);
	free_matrix(splitted_cmd);	
}

int	main(void)
{
	t_data data;
	char	*str;
	int		pid;

	set_env_lst(&data);
	while (1)
	{
		str = readline("prompt: ");
		add_history(str);
		if (!strcmp(str, "exit"))
		{
			rl_clear_history();
			free(str);
			free_env(data.env_list);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
			execute_command(str, &data);
		else
			wait(0);
		free(str);
	}
}
