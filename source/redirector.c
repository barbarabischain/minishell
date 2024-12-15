/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:09:10 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/14 21:52:55 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_redirect(char *token)
{
	if (!ft_strncmp(token, "<", 2))
		return (1);
	else if (!ft_strncmp(token, ">", 2))
		return (2);
	else if (!ft_strncmp(token, ">>", 3))
		return (3);
	else if (!ft_strncmp(token, "<<", 3))
		return (4);
	return (0);
}

int	get_next_redirect(char **cmd, int *init)
{
	while (cmd[*init])
	{
		if (is_redirect(cmd[*init]))
			return (*init + 1);
		(*init)++;
	}
	return (0);
}

void	open_file(char **cmd, int i)
{
	int	red_num;

	red_num = is_redirect(cmd[i]);
	if (red_num == 2)
		set_out(cmd[i + 1]);
	else if (red_num == 3)
		set_append(cmd[i + 1]);
	else
		set_in(cmd[i + 1]);
}

char	**build_redirects_matrix(char **cmd)
{
	int		count;
	char	**redirects_matrix;
	int		i;

	count = count_redirects(cmd);
	redirects_matrix = ft_calloc(count * 2 + 1, sizeof(void *));
	i = 0;
	count = 0;
	while (get_next_redirect(cmd, &i))
	{
		redirects_matrix[count] = ft_strdup(cmd[i]);
		redirects_matrix[count + 1] = ft_strdup(cmd[i + 1]);
		cmd[i][0] = -42;
		cmd[i + 1][0] = -42;
		count += 2;
		i++;
	}
	return (redirects_matrix);
}

void	redirect(char **cmd)
{
	int			i;
	char		**redirects;

	redirects = build_redirects_matrix(cmd);
	shell()->in_fd = 0;
	shell()->out_fd = 1;
	i = 0;
	while (get_next_redirect(redirects, &i) && !shell()->status)
		open_file(redirects, i++);
	if (contains_only_redirects(cmd, redirects))
	{
		free_matrix(redirects);
		complete_free();
		exit(0);
	}
	else
		remove_quotes(fix_cmd(cmd));
	free_matrix(redirects);
}
