/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/04 14:32:09 by babischa         ###   ########.fr       */
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

/***		doubly linked list		***/
typedef struct s_node
{
	char			*value;
	struct s_node	*prev;
	int				token;
	struct s_node	*next;
}	t_node;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

/***		MINISHELL		***/
typedef struct s_shell
{
	char			*input;
	t_env_list		*env_list;
	t_node			*cmd_list;
	int				status;
}	t_shell;

void		execution_clean(void);
void		complete_free(void);
void		execute(void);
void		execute_command(void);
void		check_exit(void);
t_shell		*shell(void);
t_env_list	*lst_new(char *key, char *value);

/*** ENV ***/
void		lst_add_ascii(t_env_list *lst, char *key, char *value);
t_env_list	*lst_find(t_env_list *lst, char *key);
t_env_list	*lst_add_next(t_env_list *lst, t_env_list *next);
void		set_env_lst(void);
void		print_env(t_env_list *lst);
void		print_env(t_env_list *lst);
void		export_env(t_env_list *lst, char *key, char *value);
void		unset_env(t_env_list *lst, char *key);
void		free_env(void);
void		print_type(char **str);
char		**env_matrix(t_env_list *env);
void		free_matrix(char **mtx);
char		**remove_quotes(char **matrix);
char		*get_value(char *env);
char		*get_key(char *env);

/***		doubly linked list functions	***/
t_node		*new_node(char *content);
void		add_node_front(t_node **node, t_node *new);
t_node		*last_node(t_node *node);
void		add_node_last(t_node **node, t_node *new);
void		print_list(t_node *stack);
void		free_list(t_node **list);
int			list_size(t_node *lst);
char		**list_to_matrix(t_node *list);
char		*nodes_to_string(t_node *temp);

// Tokens
enum e_token
{
	WORD,
	PIPE,
	OUT_R,
	IN_R,
	APPEND,
	HEREDOC
};

t_node		*find_type(t_node *lst, int type);
int			check_pipe(t_node *tokens);
int			check_out(t_node *tokens);
int			check_in(t_node *tokens);
int			check_append(t_node *tokens);
int			check_heredoc(t_node *tokens);
void		parse_input(void);
char		*put_space(char *str);
void		tokenize(void);
void		classify(t_node *tokens);
int			token_type(char *str);
void		expand(void);
char		**remove_quotes(char **matrix);
void		lexical_analyse(void);

/*** BUILTINS ***/
void		pwd(void);
void		is_builtin(t_node	*list);
t_env_list	**array_of_pointers(t_env_list	*lst);
int			env_lst_size(t_env_list *lst);
t_env_list	**sort_ascii(t_env_list	**array);
void		print_matrix(t_env_list	**array);
void		export(char **matrix);
void		echo(char **matrix);

#endif
