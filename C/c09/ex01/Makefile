SRCS  = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

all : ${NAME}

.c.o :
	${CC} ${CFLAGS} -I ./includes/ -c $< -o $@

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all fclean clean re
