NAME = cub3d

SOURCE = main.c start_events.c draw_map.c simple_hooks.c draw_ray_on_map.c \
		direction_manipulations.c draw_walls.c drawing.c new_engine.c

CC = gcc

# CFLAGS = -Wall -Wextra -Werror

# LFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

LFLAGS = libmlx_Linux.a -lXext -lX11 -lm

HEADER = raycast.h

INCLUDE = mlx.h raycast.h

INCLUDE = raycast.h

OBJS = $(SOURCE:.c=.o)

$(NAME): $(OBJS) $(HEADER)
	$(CC) -g $(OBJS) $(LFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
