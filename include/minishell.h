/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:39:53 by babischa          #+#    #+#             */
/*   Updated: 2024/09/24 17:56:40 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include "../library/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>


typedef	struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

// MINISHELL
typedef struct s_data
{
	t_env_list		*env_list;
}   t_data;

t_env_list	*lst_new(char *key, char *value);
void		lst_add_ascii(t_env_list *lst, char *key, char *value);
t_env_list	*lst_find(t_env_list *lst, char *key);
t_env_list	*lst_add_next(t_env_list *lst, t_env_list *next);
void		set_env_lst(t_data *data);
void		prit_env(t_env_list *lst);
void		export_env(t_env_list *lst, char *key, char *value);
void		unset_env(t_env_list *lst, char *key);
void		free_env(t_env_list *lst);
void print_type(char **str);

#endif
