#include "../include/minishell.h"

char	*heredoc_expand(char *line)
{
	char		*current;
	char		*subs;
	char		*full_line;
	t_env_list	*found;


	if (ft_strchr(line, '$'))
	{
		current = ft_strchr(line, '$') + 1;
		found = lst_find(shell()->env_list, current);
		if (found && (current + 1) != NULL)
		{
			subs = ft_substr(line, 0, ft_strlen(line) - ft_strlen(current) - 1);
			full_line = ft_strjoin(subs, found->value);
			free (line);
			free(subs);
			return (full_line);
		}
	}
	return (line);
}

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

void	heredoc_open(char *delimiter)
{
	char	*line;
	int		file_fd;
	char	*file_name;

	file_name = file_name_generator();
	file_fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	while (1)
	{
		line = readline("> ");
		line = heredoc_expand(line);
		if (!ft_strncmp(delimiter, line, ft_strlen(delimiter)))
			break;
		ft_putendl_fd(line, file_fd);
		free (line);
	}
	free(file_name);
	close(file_fd);
}

t_node	*find_heredoc()
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


void	heredoc()
{
	t_node	*heredoc;
	t_node	*delimiter;

	heredoc = find_heredoc();
	if (heredoc)
	{
		delimiter = find_heredoc()->next;
		heredoc_open(delimiter->value);
	}
}
