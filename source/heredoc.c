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
		if (!ft_strncmp(delimiter, line, ft_strlen(delimiter)))
			break;
		ft_putendl_fd(line, file_fd);
		free (line);
	}
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


void	heredoc() // precisa verificar o formato antes para não dar segfault
{
	t_node	*heredoc;
	t_node	*delimiter;

	heredoc = find_heredoc();
	delimiter = find_heredoc()->next;
	printf("delimiter: %s\n", delimiter->value);
}
