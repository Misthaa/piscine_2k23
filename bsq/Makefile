# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 17:20:50 by edbernar          #+#    #+#              #
#    Updated: 2023/08/02 20:24:37 by edbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/main.c\
				srcs/basic_function.c\
				srcs/ft_split.c\
				srcs/main_solver.c\
				srcs/pull_param.c\
				srcs/verif_map.c

NAME		=	bsq

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -I ./includes/

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re	: fclean all

.PHONY : re fclean all clean
