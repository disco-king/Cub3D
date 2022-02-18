#include "raycast.h"


char	*choose_texture(t_window *window)
{
	if (!window->side)
	{
		if (window->player->y > window->player->dir_y)
			return (window->textures->so);
		return (window->textures->no);
	}
	if (window->side)
	{
		if (window->player->x < window->player->dir_x)
			return (window->textures->ea);
		return (window->textures->we);
	}
	return (window->textures->no);
}

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
	int temp;

	step = (float)window->textures->text_height / (wall_height);
	text_pos = (draw_start - 720 / 2 - window->offset + wall_height / 2) * step;
	y = draw_start;
	// if (y < 0)
	// 	y = 0;
	// // if (y > 720)
	// // 	y = 10000;
	printf("in texture %d\n", y);
	adr = (int *) mlx_get_data_addr(choose_texture(window), &bpp,
			&l, &endian);
	temp = window->offset;
	// if (y + window->offset <= 0)
	// {
	// 	y = 0;
	// 	draw_end += window->offset;
	// 	window->offset = 0;
	// }
	while (y < draw_end)
	{
		window->textures->text_y = (int)text_pos & (window->textures->text_height - 1);
		text_pos += step;
		//printf("%d %d %d\n", window->textures->text_height, window->textures->text_y, window->textures->text_x);
		window->color = (adr[(int)(window->textures->text_height
			* window->textures->text_y + window->textures->text_x)]);
		pix_to_img(window->img, window->current_x, y, window->color);
		// mlx_pixel_put(window->mlx, window->window, window->current_x, y, window->color);
		y++;
	}
	window->offset = temp;
}

void	calc_texture(t_window *window)
{
	//printf("ray pos %f %f\n", window->player->dir_x, window->player->dir_y);
	if (window->side)
		window->textures->wall_x = window->player->dir_y;
	else if (!window->side)
		window->textures->wall_x = window->player->dir_x;
	window->textures->wall_x -= (floor)(window->textures->wall_x);
	window->textures->text_x = (int)(window->textures->wall_x
			* window->textures->text_width);
	if (window->side && window->player->dir_x > 0)
	//printf("texture x %d %d\n", window->textures->text_width, window->textures->text_x);
		window->textures->text_x = window->textures->text_width - window->textures->text_x - 1;
	if (!window->side && window->player->dir_y < 0)
		window->textures->text_x = window->textures->text_width - window->textures->text_x - 1;
}


void	get_texture(t_window *window)
{
	int	width;
	int	height;
	//printf("%s %ld\n", window->params->no_addr, sizeof(window->textures->no));
	window->textures->no = mlx_xpm_file_to_image(window->mlx,
			window->params->no_addr,
			&width, &height);
	window->textures->ea = mlx_xpm_file_to_image(window->mlx,
			window->params->ea_addr,
			&width, &height);
	window->textures->so = mlx_xpm_file_to_image(window->mlx,
			window->params->so_addr,
			&width, &height);
	window->textures->we = mlx_xpm_file_to_image(window->mlx,
			window->params->we_addr,
			&width, &height);
	window->textures->text_width = width;
	window->textures->text_height = height;
	printf("w and h %d %d\n", width, height);
}
