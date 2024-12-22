/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:18:40 by babischa          #+#    #+#             */
/*   Updated: 2024/12/22 14:24:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	token_type(char *str)
{
	if (!ft_strncmp(str, "|", 2))
		return (PIPE);
	else if (!ft_strncmp(str, "<", 2))
		return (IN_R);
	else if (!ft_strncmp(str, ">", 2))
		return (OUT_R);
	else if (!ft_strncmp(str, "<<", 3))
		return (HEREDOC);
	else if (!ft_strncmp(str, ">>", 3))
		return (APPEND);
	return (WORD);
}
