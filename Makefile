NAME = cub3d

NAME_B = $(NAME)

LIBFT = ./libft/libft.a

SRC = start_events.c key_hooks.c

SRC_B = bonus/start_events.c bonus/mouse_hook.c \
		bonus/draw_map.c bonus/map_staff.c \
		bonus/key_hooks.c

MAIN_SRC = main.c draw_ray_on_map.c \
		direction_manipulations.c draw_walls.c drawing.c new_engine.c \
		simple_hooks_part_two.c new_engine_part_two.c \
		texture_handling.c

SRC_P = map_parsing/param_parse.c map_parsing/map_parse.c \
		map_parsing/gnl.c map_parsing/param_checks.c \
		map_parsing/line_parsing.c map_parsing/column_parsing.c \
		map_parsing/map_utils.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

MAIN_OBJ = $(MAIN_SRC:.c=.o) $(SRC_P:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

# LFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

# LFLAGS = libmlx_Linux.a -lXext -lX11 -lm

LFLAGS = -lmlx_Linux -lXext -lX11 -lm

HEADER = raycast.h

all: $(NAME)

%.o : %.c $(HEADER)
		$(CC) -c $< -o $@

$(LIBFT):
		$(MAKE) -C ./libft

$(NAME): $(OBJ) $(MAIN_OBJ) $(LIBFT)
		$(CC) $(OBJ) $(MAIN_OBJ) -L ./libft/ -lft $(LFLAGS) -o $@

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJ) $(MAIN_OBJ) $(OBJ_B)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all

bonus: fclean
	make OBJ="$(OBJ_B)" all
