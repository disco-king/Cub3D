NAME = cub3d

SOURCE = main.c start_events.c draw_map.c simple_hooks.c draw_ray_on_map.c \
		direction_manipulations.c draw_walls.c drawing.c new_engine.c \
		map_parsing/param_parse.c map_parsing/map_parse.c map_parsing/gnl.c \
		map_parsing/libft/*.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

# LFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

LFLAGS = -lmlx_Linux -lXext -lX11 -lm

HEADER = raycast.h

INCLUDE = mlx.h raycast.h map_parsing/parse.h

INCLUDE = raycast.h

OBJS = $(SOURCE:.c=.o)

$(NAME): $(OBJS) $(HEADER)
	$(CC) -g $(OBJS) $(FLAGS) $(LFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
