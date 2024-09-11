# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:42:15 by babischa          #+#    #+#              #
#    Updated: 2024/09/11 15:23:26 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISHELL	:=	minishell

CC 			:=	cc
FLAGS 		:=	-Wall -Werror -Wextra

LIBFT	 	:=	./library/libft
HEADERS 	:=	-I ./include -I $(LIBFT)/include
LIB			:=	$(LIBFT)/libft.a

SRC_PUSH	:=	main

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
	@printf "   ignore_libreadline_leaks\n" >> leak_readline
	@printf "    Memcheck:Leak\n" >> leak_readline
	@printf "    ...\n" >> leak_readline
	@printf "    obj:/libreadline.so.\n" >> leak_readline
	@printf "}\n" >> leak_readline

.PHONY: all clean fclean re make_printf make_libft objects bonus

.SILENT:
