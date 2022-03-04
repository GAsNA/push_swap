# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleseur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 14:34:54 by rleseur           #+#    #+#              #
#    Updated: 2022/03/04 03:05:01 by rleseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### DESIGN #######

# Style de typo :
_FIN			=	\033[0m
_GRAS			=	\033[1m
_ITA			=	\033[3m
_SOUS			=	\033[4m
_CLIGN			=	\033[5m
_REV			=	\033[7m

# Couleurs des lettres :
_GRIS			=	\033[30m
_ROUGE			=	\033[31m
_VERT			=	\033[32m
_JAUNE			=	\033[33m
_BLEU			=	\033[34m
_VIOLET			=	\033[35m
_CYAN			=	\033[36m
_BLANC			=	\033[37m

# Couleurs de fonds :
_IGRIS			=	\033[40m
_IROUGE			=	\033[41m
_IVERT			=	\033[42m
_IJAUNE			=	\033[43m
_IBLEU			=	\033[44m
_IVIOLET		=	\033[45m
_ICYAN			=	\033[46m
_IBLANC			=	\033[47m

# Appel
_VALID			=	/bin/echo -e "${_JAUNE}\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n\
					${_VERT}${_IVIOLET}\#\# $1${_FIN}"
_EMOJI			=	/bin/echo -e "${_GRAS}${_VIOLET}$1${_FIN}\n"

CREATED_BIN		=	@$(call _VALID,"Binary created!")
CREATED_LIBFT	=	@$(call _VALID,"Libft library created!")
DELETED_OBJS	=	@$(call _VALID,"Objs deleted!")
DELETED_BIN		=	@$(call _VALID,"Binary deleted!")


####### MAKEFILE #######

### Variables

LIBFT_PATH		=	./librairies/libft/
LIBFT			=	${LIBFT_PATH}libft.a

SRCS_PATH		=	./srcs/
SRCS			=	${SRCS_PATH}main.c					\
					${SRCS_PATH}get_args.c				\
					${SRCS_PATH}check_args.c			\
					${SRCS_PATH}is_sort.c				\
					${SRCS_PATH}algorithm_three.c		\
					${SRCS_PATH}algorithm_five.c		\
					${SRCS_PATH}algorithm_infinity.c	\
					${SRCS_PATH}algorithm_infinity2.c	\
					${SRCS_PATH}lis.c					\
					${SRCS_PATH}rotate_to_min.c			\
					${SRCS_PATH}make_mov.c				\
					${SRCS_PATH}instructions.c			\
					${SRCS_PATH}operations.c			\
					${SRCS_PATH}create_list.c			\
					${SRCS_PATH}utils.c					\
					${SRCS_PATH}free.c					\
					${SRCS_PATH}errors.c

OBJS_PATH		=	./objs/
OBJS			=	${SRCS:.c=.o}

HEADERS_PATH	=	./headers/
HEADER			=	${HEADERS_PATH}push_swap.h

NAME			=	push_swap

CC				=	clang
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -g3

### Commandes

all:			${NAME}

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
				${CREATED_BIN}

.c.o:
				${CC} -c ${CFLAGS} -I${HEADERS_PATH} $^ -o $@

${LIBFT}:
				make -C ${LIBFT_PATH}
				${CREATED_LIBFT}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${OBJS}
				${DELETED_OBJS}

fclean:			clean
				make -C ${LIBFT_PATH} fclean
				${RM} ${NAME}
				${DELETED_BIN}

re:				fclean all

.PHONY:			all clean fclean re libft
