NAME = cub3d

SOURCE = main.c start_events.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#LFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

LFLAGS = libmlx_Linux.a -lXext -lX11 -lm -lz -o

HEADER = raycast.h

#INCLUDE = -L /usr/local/lib -lmlx raycast.h

INCLUDE = mlx.h raycast.h

OBJS = $(SOURCE:.c=.o)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
