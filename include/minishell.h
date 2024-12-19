/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:21:59 by madias-m          #+#    #+#             */
/*   Updated: 2024/12/18 21:05:33 by madias-m         ###   ########.fr       */
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
# include <signal.h>

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
	char			*target_error;
	char			***cmd_array;
	int				cmd_array_size;
	int				in_fd;
	int				out_fd;
}	t_shell;

void		execution_clean(void);
void		complete_free(void);
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
	HEREDOC
};

t_node		*find_type(t_node *lst, int type);
int			check_pipe(t_node *tokens);
int			check_out(t_node *tokens);
int			check_in(t_node *tokens);
int			check_append(t_node *tokens);
int			check_heredoc(t_node *tokens);
int			set_error_message(char *token_value);
void		parse_input(void);
char		*put_spaces(char *str);
void		tokenize(void);
void		classify(t_node *tokens);
int			token_type(char *str);
void		expand(void);
char		**remove_quotes(char **matrix);
void		lexical_analyse(void);
void		build_command_array(void);
void		expand_status(t_node **dest, int *i);
void		quote_handler(char *inside_quotes, char actual_char);

/*** EXECUTION */
void		execute(void);
void		check_existence(char *path, int i);
void		check_executable(char *path, int i);
void		finalize_processes(int *pids);
int			exec_single_builtin(void);

/*** REDIRECT */
void		redirect(char **cmd);
int			is_redirect(char *token);
int			contains_only_redirects(char **cmd, char **redirects);
void		reorganize(char **cmd);
int			get_next_redirect(char **cmd, int *init);
void		set_out(char *file_name);
void		set_in(char *file_name);
void		set_append(char *file_name);
int			count_redirects(char **cmd);
char		**fix_cmd(char **cmd);

/*** BUILTINS ***/
void		pwd(void);
int			is_builtin(char	**cmd_array);
void		execute_builtins(char	**cmd_array);
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
void		env(char **matrix);
void		check_exit(char **cmd_list);
void		execute_exit(void);

/*** HEREDOC ***/
void		heredoc(t_node **cmd_list);
char		*heredoc_expand(char *line);
int			has_quotes(char *line);

/*** SIGNALS ***/
void		signal_init(void);
void		signal_execution_init(int pid);
void		signal_heredoc_init(void);

#endif
