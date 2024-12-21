/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:49 by babischa          #+#    #+#             */
/*   Updated: 2024/12/21 12:39:26 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_null_line(char **file_name)
{
	if (shell()->status == 130)
	{
		free (*file_name);
		*file_name = NULL;
	}
	ft_putchar_fd('\n', 1);
}

char	*heredoc_read(char *delimiter)
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
		if (line == NULL)
		{
			handle_null_line(&file_name);
			break ;
		}
		if (!ft_strcmp(delimiter, line))
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

int	heredoc(t_node	**cmd_list)
{
	t_node	*heredoc;
	t_node	*delimiter;
	char	*filename;

	shell()->config = 2;
	heredoc = find_heredoc(*cmd_list);
	while (heredoc && heredoc_is_valid(heredoc))
	{
		delimiter = heredoc->next;
		filename = heredoc_read(delimiter->value);
		if (!filename)
			return (0);
		free(delimiter->value);
		delimiter->value = filename;
		heredoc = find_heredoc(heredoc->next);
	}
	return (1);
}
