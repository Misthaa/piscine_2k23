SRCS  = ./do-op.c ./calc.c

NAME = do-op

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.c.o :
	@${CC} ${CFLAGS} -c $< -o $@

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${NAME}

re : fclean all

.PHONY : all fclean clean re
