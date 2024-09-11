# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babischa <babischa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 11:24:00 by babischa          #+#    #+#              #
#    Updated: 2024/08/18 16:20:47 by babischa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra -c
SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_itoa.c \
	   ft_split.c \
	   ft_striteri.c \
	   ft_strmapi.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_atol.c


OBJ	= ${SRCS:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJ}

%.o: %.c
	cc ${FLAGS} $< -o $@
	ar -crs ${NAME} $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
