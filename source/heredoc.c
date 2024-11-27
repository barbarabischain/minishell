/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:49 by babischa          #+#    #+#             */
/*   Updated: 2024/11/27 13:41:49 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *file_name_generator(void)
{
	static int	index;
	char		*index_name;
	char		*full_name;

	index_name = ft_itoa(index);
	full_name  = ft_strjoin("/tmp/heredoc", index_name);
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
	printf("expand value: %d\n", expand);
	// if (expand == -1)
	// {
	// 	printf("%s: Invalid Sintax\n", delimiter);
	// 	return ;
	// }
	while (1)
	{
		line = readline("> ");
		if (expand == 0)
			line = heredoc_expand(line);
		if (!ft_strncmp(delimiter, line, ft_strlen(delimiter)))
			break;
		ft_putendl_fd(line, file_fd);
		free (line);
	}
	return (file_name);
}

t_node	*find_heredoc(void)
{
	t_node	*current;

	current = shell()->cmd_list;
	while (current)
	{
		if (current->token == HEREDOC)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	delete_heredoc_operator(t_node	*heredoc)
{
	t_node	*prev_node;
	t_node	*next_node;

	prev_node = heredoc->prev;
	next_node = heredoc->next;

	prev_node->next = next_node;
	next_node->prev = prev_node;
	if (heredoc != NULL)
	{
		free(heredoc->value);
		free(heredoc);
	}
}

void	heredoc(void)
{
	t_node	*heredoc;
	t_node	*delimiter;
	char	*filename;

	heredoc = find_heredoc();
	while (heredoc)
	{
		delimiter = find_heredoc()->next;
		filename = heredoc_open(delimiter->value);
		free(delimiter->value);
		delimiter->value = filename;
		delete_heredoc_operator(heredoc);
		heredoc = find_heredoc();
	}
}
