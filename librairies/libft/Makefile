# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleseur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 13:54:15 by rleseur           #+#    #+#              #
#    Updated: 2022/03/09 09:07:59 by rleseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			ft_atoi.c		\
				ft_bzero.c		\
				ft_calloc.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_itoa.c		\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_putchar_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c	\
				ft_split.c		\
				ft_strchr.c		\
				ft_strdup.c		\
				ft_striteri.c	\
				ft_strjoin.c	\
				ft_strlcat.c	\
				ft_strlcpy.c	\
				ft_strlen.c		\
				ft_strmapi.c	\
				ft_strncmp.c	\
				ft_strcmp.c		\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_strtrim.c	\
				ft_substr.c		\
				ft_tolower.c	\
				ft_toupper.c	\
				get_next_line.c

SRCS_BONUS =	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

OBJS =			${SRCS:.c=.o}

OBJS_BONUS =	${SRCS_BONUS:.c=.o}

HEADER =		./libft.h

NAME =			libft.a

CFLAGS =		-Wall -Wextra -Werror

all:			${NAME}

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}

bonus:			${OBJS_BONUS}
				ar rc ${NAME} ${OBJS_BONUS}

.c.o:
				clang -c ${CFLAGS} -include${HEADER} $^ -o $@

clean:
				rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all bonus clean fclean re
