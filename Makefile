# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babischa <babischa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:42:15 by babischa          #+#    #+#              #
#    Updated: 2024/09/30 13:40:38 by babischa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISHELL	:=	minishell

CC 			:=	cc
FLAGS 		:=	-Wall -Werror -Wextra -g3

LIBFT	 	:=	./library/libft
HEADERS 	:=	-I ./include -I $(LIBFT)/include
LIB			:=	$(LIBFT)/libft.a

SRC_PUSH	:=	main \
				token_type env_lst envs \
				double_lst

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
	rm leak_readline
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
	@printf "   <Readline>\n" >> leak_readline
	@printf "   Memcheck:Leak\n" >> leak_readline
	@printf "   match-leak-kinds: definite\n" >> leak_readline
	@printf "   fun:malloc\n" >> leak_readline
	@printf "   fun:xmalloc\n" >> leak_readline
	@printf "   fun:rl_add_undo\n" >> leak_readline
	@printf "   fun:rl_insert_text\n" >> leak_readline
	@printf "   fun:_rl_insert_char\n" >> leak_readline
	@printf "   fun:rl_insert\n" >> leak_readline
	@printf "   fun:_rl_dispatch_subseq\n" >> leak_readline
	@printf "   fun:readline_internal_char\n" >> leak_readline
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

.PHONY: all clean fclean re make_printf make_libft objects bonus

.SILENT:
