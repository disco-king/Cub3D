#include "raycast.h"

void	calc_texture_y(t_window *window, int wall_height, int draw_start, int draw_end)
{
	float	step;
	float	text_pos;
	int		y;
	t_data	img;
	int	*adr;
	int	bpp;
	int	l;
	int	endian;

	step = (float)window->textures->text_height / (wall_height);
	text_pos = (draw_start - 720 / 2 + wall_height / 2) * step;
	y = draw_start;
	adr = (int *)mlx_get_data_addr(window->textures->no, &bpp,
			&l, &endian);
	while (y < draw_end)
	{
		window->textures->text_y = (int)text_pos & (window->textures->text_height - 1);
		text_pos += step;
		//printf("%d %d %d\n", window->textures->text_height, window->textures->text_y, window->textures->text_x);
		window->color = (adr[(int)(window->textures->text_height
			* window->textures->text_y + window->textures->text_x)]);
		// window->color = adr[(int)((window->textures->text_y * 64 + window->textures->text_x) * 3
		// 					+ window->distance * 64 * 64 * 3)];
		// printf("color is %d\n", window->img->addr[(int)(window->textures->text_height
		// 	* window->textures->text_y + window->textures->text_x)]);
		// window->img->addr = (char *)adr;
		// window->img->bits_per_pixel = bpp;
		// window->img->endian = endian;
		// window->img->line_length = l;
		// window->img->img = window->textures->no;
		//pix_to_img(&img, window->current_x, y, window->color);
		mlx_pixel_put(window->mlx, window->window, window->current_x, y, window->color);
		y++;
	}
}

void	calc_texture(t_window *window)
{
	//printf("ray pos %f %f\n", window->player->dir_x, window->player->dir_y);
	if (window->side)
		window->textures->wall_x = window->player->y
			+ window->distance * window->player->dir_y;
	else if (!window->side)
		window->textures->wall_x = window->player->x
			+ window->distance * window->player->dir_x;
	window->textures->wall_x -= (floor)(window->textures->wall_x);
	window->textures->text_x = (int)(window->textures->wall_x
			* window->textures->text_width);
	// if (window->side && window->player->dir_x > 0)
	// //printf("texture x %d %d\n", window->textures->text_width, window->textures->text_x);
	// 	window->textures->text_x = window->textures->text_width - window->textures->text_x - 1;
	// if (!window->side && window->player->dir_y < 0)
	// 	window->textures->text_x = window->textures->text_width - window->textures->text_x - 1;
	// if (!window->side)
	// 	window->textures->text_x = (int)(window->player->dir_x / 2.0) % window->textures->text_width;
	// else
	// 	window->textures->text_x = (int)(window->player->dir_y / 2.0) % window->textures->text_width;
}


void	get_texture(t_window *window)
{
	int	width;
	int	height;
	//printf("%s %ld\n", window->params->no_addr, sizeof(window->textures->no));
	window->textures->no = mlx_xpm_file_to_image(window->mlx,
			window->params->no_addr,
			&width, &height);
	//write(1, "here\n", 5);
	// window->textures->ea = mlx_xpm_file_to_image(window->mlx,
	// 		window->params->ea_addr,
	// 		&width, &height);
	// window->textures->so = mlx_xpm_file_to_image(window->mlx,
	// 		window->params->so_addr,
	// 		&width, &height);
	// window->textures->we = mlx_xpm_file_to_image(window->mlx,
	// 		window->params->we_addr,
	// 		&width, &height);
	window->textures->text_width = width;
	window->textures->text_height = height;
	printf("w and h %d %d\n", width, height);
}
