/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:49 by babischa          #+#    #+#             */
/*   Updated: 2024/12/16 16:33:22 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*file_name_generator(void)
{
	static int	index;
	char		*index_name;
	char		*full_name;

	index_name = ft_itoa(index);
	full_name = ft_strjoin("/tmp/heredoc", index_name);
	index++;
	free(index_name);
	return (full_name);
}

char	*heredoc_open(char *delimiter)
{
	char	*line;
	int		file_fd;
	char	*file_name;
	int		expand;

	file_name = file_name_generator();
	file_fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	expand = has_quotes(delimiter);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || !ft_strcmp(delimiter, line) || g_signal == SIGINT)
			break ;
		if (expand == 0)
			line = heredoc_expand(line);
		ft_putendl_fd(line, file_fd);
		free (line);
	}
	close(file_fd);
	return (file_name);
}

t_node	*find_heredoc(t_node *list)
{
	t_node	*current;

	current = list;
	while (current)
	{
		if (current->token == HEREDOC)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int	heredoc_is_valid(t_node *heredoc)
{
	if (heredoc && heredoc->next == NULL)
		return (0);
	return (1);
}

void	heredoc(t_node	**cmd_list)
{
	t_node	*heredoc;
	t_node	*delimiter;
	char	*filename;

	heredoc = find_heredoc(*cmd_list);
	while (heredoc && heredoc_is_valid(heredoc))
	{
		signal_heredoc_init();
		delimiter = heredoc->next;
		filename = heredoc_open(delimiter->value);
		free(delimiter->value);
		delimiter->value = filename;
		heredoc = find_heredoc(heredoc->next);
	}
}
