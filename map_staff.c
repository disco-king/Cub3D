#include "raycast.h"

void	draw_surroundings(t_window *window)
{
	void	*map_image;
	int		height;
	int		width;
	int		x;
	int		y;

	x = (int)window->player->x - 2;
	y = (int)window->player->y - 2;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	map_image = mlx_xpm_file_to_image(window->mlx, "./brick.xpm",
			&height, &width);
	while (window->map[y][x] && y < 6)
	{
		while (window->map[y][x] && x < 6)
		{
			if (window->map[y][x] == '1')
			{
				mlx_put_image_to_window(window->mlx, window->window,
					map_image, 640 - 64 * 2 + x * 64, 360 - 64 * 2 + y * 64);
			}
			x++;
		}
		x = (int)window->player->x - 2;
		y++;
	}	
}

void	draw_small_map(t_window *window)
{
	void	*map_image;
	int		height;
	int		width;
	int		x;
	int		y;

	x = (int)window->player->x;
	y = (int)window->player->y;
	map_image = mlx_xpm_file_to_image(window->mlx, "./main_hero.xpm",
			&height, &width);
	mlx_clear_window(window->mlx, window->window);
		draw_surroundings(window);
	mlx_put_image_to_window(window->mlx, window->window, map_image, 640 + 4 * 32 + 16, 360 + 16);
}
