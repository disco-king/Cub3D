NAME = cub3d

LIBFT = ./libft/libft.a

LIBFT_O = ./libft/*.o

SRCS = start_events.c key_hooks.c $(MAIN_SRC) $(SRCS_P)

MAIN_SRC = main.c draw_ray_on_map.c \
		direction_manipulations.c draw_walls.c drawing.c new_engine.c \
		simple_hooks_part_two.c new_engine_part_two.c \
		texture_handling.c

SRCS_P = map_parsing/param_parse.c map_parsing/map_parse.c \
		map_parsing/gnl.c map_parsing/param_checks.c \
		map_parsing/line_parsing.c map_parsing/column_parsing.c \
		map_parsing/map_utils.c

SRCS_B = bonus/mouse_hook.c bonus/start_events.c \
		bonus/draw_map.c bonus/map_staff.c \
		bonus/key_hooks.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

MAIN_OBJS = $(MAIN_SRC:.c=.o) $(SRCS_P:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

#  LFLAGS = libmlx_Linux.a -lXext -lX11 -lm

# LFLAGS = -lmlx_Linux -lXext -lX11 -lm

HEADER = raycast.h

INCLUDE = mlx.h raycast.h map_parsing/parse.h

all: $(NAME)

%.o : %.c $(HEADER)
		$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS) $(MAIN_OBJS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(MAIN_OBJS) $(FLAGS) $(LIBFT) $(LFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re:	fclean all

bonus: fclean
	make OBJS="$(OBJS_B)" all
