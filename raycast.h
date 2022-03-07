/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:41:45 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:34:59 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "./map_parsing/parse.h"
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define ESC 65307
# define W 13
# define S 1
# define A 0
# define D 2
# define W2 119
# define S2 115
# define A2 97
# define D2 100
# define LA 123
# define RA 124
# define LA2 65361
# define RA2 65363
# define WIN_Y 720
# define WIN_X 1280
# define M 46
# define M2 109
# define STEP 0.05
# define PI_8 0.392699082
# define PI_16 0.196349541

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_textures
{
	void	*no;
	void	*ea;
	void	*so;
	void	*we;
	int		*width;
	int		*height;
	int		text_x;
	int		text_y;
	float	wall_x;
	int		wall_y;
	int		text_width;
	int		text_height;
}	t_textures;

typedef struct s_data {
	void	*img[2];
	char	*addr[2];
	void	*cur_img;
	char	*cur_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player
{
	float	x;
	float	y;
	int		start_direction;
	float	dir_x;
	float	dir_y;
	float	angle;
}	t_player;

typedef struct s_window
{
	t_player	*player;
	char		**map;
	void		*mlx;
	void		*window;
	long		color;
	t_data		*img;
	float		distance;
	float		camera_angle;
	int			x_border;
	int			y_border;
	int			side;
	int			current_x;
	int			toggle_map;
	int			mouse_x;
	int			mouse_y;
	int			offset;
	float		distance_vert;
	float		distance_hor;
	float		step_x;
	float		step_y;
	int			hit;
	float		v_x;
	float		v_y;
	t_params	*params;
	t_textures	*textures;
}	t_window;

void	init_window(t_window *window, char **map);
void	scale_map(int i, int j, t_window *window, int color);
void	error_exit(int code);

/*simple hoooks*/
int		key_release(int keycode, t_window *window);
int		key_hook(int keycode, t_window *window);
void	get_move(t_player *player, float move[2], int code);

/*draw_ray on map*/
void	count_ray(t_window *window, float xend, float yend, int color);
void	find_end_points(t_window *window);

/*angle manipulations*/
void	change_dir(t_window *window, int keycode);
void	draw_all_rays(t_window *window, int color);

/*draw vert*/
void	draw_wall(t_window *window, int x);
void	color_window(t_window *window);

/*faster drawing section*/
void	get_new_image(void **new1, void **new2, t_window *win);
void	pix_to_img(t_data *data, int x, int y, int color);

void	redraw(t_window *window);
float	count_distance(t_window *window);
int		check_borders(t_window *window);
float	fix_angle(float angle);

/*textures*/
void	get_texture(t_window *window);
void	calc_texture_y(t_window *window, int wall_height,
			int draw_start, int draw_end);
void	calc_texture(t_window *window);

/*map*/
void	draw_small_map(t_window *window);

/*mouse view*/
int		mouse_hook(int x, int y, t_window *window);
int		close_mouse(void);

#endif
