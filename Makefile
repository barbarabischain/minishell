# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:42:15 by babischa          #+#    #+#              #
#    Updated: 2024/12/22 14:24:41 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISHELL	:=	minishell

CC 			:=	cc
FLAGS 		:=	-Wall -Werror -Wextra -g3

LIBFT	 	:=	./library/libft
HEADERS 	:=	-I ./include -I $(LIBFT)/include
LIB			:=	$(LIBFT)/libft.a

SRC_PUSH	:=	main shell_attr\
				exit \
				token_type env_lst set_env_lst \
				envs_utils quotes \
				double_list free_list matrix \
				parser expand shell \
				builtins pwd echo tokenizer export export_utils unset cd env\
				executor free nodes_to_string classifier lexical_analyser \
				heredoc heredoc_expansion \
				check_operators parser_utils command_array \
				redirector out_redirect reorganizer in_redirect append_redirect \
				signals_init signals_heredoc executor_utils \
				status redirector_utils convert_status

OBJ_PUSH	:=	$(addprefix objects/, $(addsuffix .o, $(SRC_PUSH)))

all: make_libft $(MINISHELL) leak_readline

make_libft:
	$(MAKE) -C $(LIBFT)

objects/%.o: source/%.c | objects
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) ; \
	echo "Compiling: $(notdir $<)"

$(MINISHELL): $(OBJ_PUSH)
	$(CC) $(OBJ_PUSH) $(LIB) $(HEADERS) -l readline -o $(MINISHELL)

objects:
	mkdir -p objects

v: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --trace-children-skip='/bin/,/sbin/' \
	--keep-debuginfo=yes --suppressions=leak_readline --track-fds=yes ./$(MINISHELL)

bonus: all

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -rf objects

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	if [ -f leak_readline ]; then \
        rm leak_readline; \
    fi
	rm -rf $(MINISHELL)

re: fclean all

leak_readline:
	@printf "{\n" > leak_readline
	@printf "   <Readline>\n" >> leak_readline
	@printf "   Memcheck:Leak\n" >> leak_readline
	@printf "   match-leak-kinds: reachable\n" >> leak_readline
	@printf "   ...\n" >> leak_readline
	@printf "   fun:readline\n" >> leak_readline
	@printf "   ...\n" >> leak_readline
	@printf "}\n" >> leak_readline
	@printf "{\n" >> leak_readline
	@printf "   <AddHistory>\n" >> leak_readline
	@printf "   Memcheck:Leak\n" >> leak_readline
	@printf "   match-leak-kinds: reachable\n" >> leak_readline
	@printf "   fun:malloc\n" >> leak_readline
	@printf "   fun:xmalloc\n" >> leak_readline
	@printf "   fun:add_history\n" >> leak_readline
	@printf "   ...\n" >> leak_readline
	@printf "}\n" >> leak_readline
	@printf "{\n" >> leak_readline
	@printf "   <Heredoc Readline Leak>\n" >> leak_readline
	@printf "   Memcheck:Leak\n" >> leak_readline
	@printf "   match-leak-kinds: definite\n" >> leak_readline
	@printf "   fun:malloc\n" >> leak_readline
	@printf "   fun:xmalloc\n" >> leak_readline
	@printf "   fun:readline_internal_teardown\n" >> leak_readline
	@printf "   fun:readline\n" >> leak_readline
	@printf "   fun:heredoc_open\n" >> leak_readline
	@printf "   fun:heredoc\n" >> leak_readline
	@printf "   fun:main\n" >> leak_readline
	@printf "   ...\n" >> leak_readline
	@printf "}\n" >> leak_readline
	@printf "{\n" >> leak_readline
	@printf "   <Readline Teardown Leak>\n" >> leak_readline
	@printf "   Memcheck:Leak\n" >> leak_readline
	@printf "   match-leak-kinds: definite\n" >> leak_readline
	@printf "   fun:malloc\n" >> leak_readline
	@printf "   fun:xmalloc\n" >> leak_readline
	@printf "   fun:readline_internal_teardown\n" >> leak_readline
	@printf "   fun:readline\n" >> leak_readline
	@printf "   ...\n" >> leak_readline
	@printf "}\n" >> leak_readline



.PHONY: all clean fclean re make_printf make_libft objects bonus

.SILENT:
