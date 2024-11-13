#include "../include/minishell.h"

void	heredoc(char *delimiter)
{
	char	*line;
	int		file_fd;

	while (1)
	{
		line = readline("> ");
		file_fd = open("/tmp/heredoc.tmp", O_CREAT |O_WRONLY | O_TRUNC, 0644);
		ft_putendl_fd(line, file_fd);
		if (!ft_strncmp(delimiter, line, ft_strlen(delimiter)))
			break;
	}
}
