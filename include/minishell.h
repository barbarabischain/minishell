/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/24 08:55:09 by madias-m         ###   ########.fr       */
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
	char			*error_message;
	char			***cmd_array;
	int				in_fd;
	int				out_fd;
}	t_shell;

void		execution_clean(void);
void		complete_free(void);
void		execute(void);
void		check_exit(void);
t_shell		*shell(void);
t_env_list	*lst_new(char *key, char *value);

/*** ENV ***/
void		lst_add_ascii(t_env_list *lst, char *key, char *value);
t_env_list	*lst_find(char *key);
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
	HEREDOC,
	F_READ,
	F_WRITE
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
void		identifie_files(void);
void		build_command_array(void);

/*** REDIRECTION */
void		redirect(char **cmd);
void		reorganize(char **cmd);
void		set_out(char *file_name);
void		set_in(char *file_name);
void		set_append(char *file_name);


/*** BUILTINS ***/
void		pwd(void);
int			is_builtin(t_node	*list);
void		execute_builtins(t_node	*list);
t_env_list	**array_of_pointers(t_env_list	*lst);
int			env_lst_size(t_env_list *lst);
t_env_list	**sort_ascii(t_env_list	**array);
void		print_matrix(t_env_list	**array);
void		export(char **matrix);
int			is_valid_name(char	*name);
void		echo(char **matrix);
int			matrix_len(char	**matrix);
void		unset(char	**matrix);
void		cd(char	**cmd_matrix);
void		env(char **cmd_list);

#endif
