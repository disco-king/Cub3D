SRCS	=	gnl.c param_parse.c proto_parse.c \
			map_parse.c \

INCLUDES = parse.h

OBJS	= ${SRCS:%.c=%.o}

LIBFT_A	= libft/libft.a
LIBFT_OBJS	= ${LIBFT:%.c=%.o}

NAME	= parse

CC		= gcc
RM		= rm -rf
FLAGS	= -Wall -Wextra -Werror

all:	libft ${NAME}

${NAME}:	${OBJS} ${INCLUDES}
			${CC} -g ${OBJS} ${LIBFT_A} -o ${NAME}

.o: .c	${INCLUDES}
		${CC} -g $< -o $@

libft:
	make -C libft

clean:
	${RM} ${OBJS}
	make -C libft clean

fclean: clean
	${RM} ${NAME}
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft