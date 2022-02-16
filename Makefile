NAME = cub3d

LIBA = libft.a

LIBA_C = ./map_parsing/libft/*.c

LIBA_H = ./map_parsing/libft/libft.h

SOURCE = main.c start_events.c draw_map.c simple_hooks.c draw_ray_on_map.c \
		direction_manipulations.c draw_walls.c drawing.c new_engine.c \
		map_parsing/param_parse.c map_parsing/map_parse.c map_parsing/gnl.c \
		texture_handling.c map_staff.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

# LFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

# LFLAGS = libmlx_Linux.a -lXext -lX11 -lm

 LFLAGS = -lmlx_Linux -lXext -lX11 -lm

HEADER = raycast.h

INCLUDE = mlx.h raycast.h map_parsing/parse.h

#INCLUDE = raycast.h

OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(LIBA): $(LIBA_C) $(LIBA_H)
		cd ./map_parsing/libft/; \
		make; \
		mv $(LIBA) ../..; \
		cd ./map_parsing/libft/; \
		make clean

$(NAME): $(OBJS) $(HEADER) $(LIBA)
	$(CC) -g $(OBJS) $(FLAGS) $(LIBA) $(LFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBA)

re:	fclean all
