/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:22:34 by babischa          #+#    #+#             */
/*   Updated: 2024/12/21 12:38:06 by babischa         ###   ########.fr       */
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

char	*heredoc_expand(char *line)
{
	char		*current;
	char		*subs;
	char		*full_line;
	t_env_list	*found;

	if (ft_strchr(line, '$'))
	{
		current = ft_strchr(line, '$') + 1;
		found = lst_find(current);
		if (found && *(current + 1) != '\0')
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

int	count_char(char	*line, int c)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

int	has_quotes(char *line)
{
	int	simple_quotes;
	int	double_quotes;

	simple_quotes = count_char(line, '\'');
	double_quotes = count_char(line, '\"');
	if (simple_quotes == 0 && double_quotes == 0)
		return (0);
	if (simple_quotes % 2 == 0 && double_quotes % 2 == 0)
		return (1);
	return (-1);
}
