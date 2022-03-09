# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleseur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 14:34:54 by rleseur           #+#    #+#              #
#    Updated: 2022/03/09 09:08:49 by rleseur          ###   ########.fr        #
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
CREATED_BIN_B	=	@${call _VALID,"Binary bonus created!"}
CREATED_LIBFT	=	@$(call _VALID,"Libft library created!")
CREATED_GNL		=	@$(call _VALID,"GNL library created!")
DELETED_OBJS	=	@$(call _VALID,"Objs deleted!")
DELETED_BIN		=	@$(call _VALID,"Binary deleted!")


####### MAKEFILE #######

### Variables

LIBFT_PATH		=	./librairies/libft/
LIBFT			=	${LIBFT_PATH}libft.a

SRCS_PATH		=	./srcs/
OBJS_PATH		=	./objs/
FILES			=	main.c					\
					get_args.c				\
					check_args.c			\
					is_sort.c				\
					algorithm_three.c		\
					algorithm_five.c		\
					algorithm_infinity.c	\
					algorithm_infinity2.c	\
					lis.c					\
					rotate_to_min.c			\
					make_mov.c				\
					instructions.c			\
					operations.c			\
					create_list.c			\
					utils.c					\
					free.c					\
					errors.c
SRCS			=	${addprefix ${SRCS_PATH}, ${FILES}}
OBJS			=	${addprefix ${OBJS_PATH}, ${FILES:.c=.o}}

SRCS_B_PATH		=	./srcs_b/
OBJS_B_PATH		=	./objs_b/
FILES_B			=	main.c			\
					check_args.c	\
					actions.c		\
					operations.c	\
					write.c			\
					get_args.c		\
					create_list.c	\
					utils.c			\
					free.c
SRCS_B			=	${addprefix ${SRCS_B_PATH}, ${FILES_B}}
OBJS_B			=	${addprefix ${OBJS_B_PATH}, ${FILES_B:.c=.o}}

HEADERS_PATH	=	./headers/
HEADER			=	${HEADERS_PATH}push_swap.h
HEADER_B		=	${HEADERS_PATH}push_swap_b.h

NAME			=	push_swap
NAME_B			=	checker

CC				=	clang
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -g3

### Commandes

all:			${NAME}

bonus:			${NAME_B}

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
				${CREATED_BIN}

${NAME_B}:		${OBJS_B} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS_B} ${LIBFT} -o ${NAME_B}
				${CREATED_BIN_B}

${OBJS_PATH}%.o:	${SRCS_PATH}%.c
				mkdir -p ${dir $@}
				${CC} -c ${CFLAGS} -I${HEADERS_PATH} $^ -o $@

${OBJS_B_PATH}%.o:	${SRCS_B_PATH}%.c
				mkdir -p ${dir $@}
				${CC} -c ${CFLAGS} -I${HEADERS_PATH} $^ -o $@

${LIBFT}:
				make -C ${LIBFT_PATH}
				${CREATED_LIBFT}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${OBJS_PATH}
				${RM} ${OBJS_B_PATH}
				${DELETED_OBJS}

fclean:			clean
				make -C ${LIBFT_PATH} fclean
				${RM} ${NAME}
				${RM} ${NAME_B}
				${DELETED_BIN}

re:				fclean all

.PHONY:			all bonus clean fclean re libft
