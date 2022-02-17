#include "raycast.h"

int	render_weapon(t_window *window)
{
	void	*image;
	int		width;
	int		height;
	int		i;

	i = 0;
	image = mlx_xpm_file_to_image(window->mlx, "./Weapon_1.xpm", &width, &height);
	mlx_put_image_to_window(window->mlx, window->window, image, 640, 360);
	while (1)
	{
		mlx_put_image_to_window(window->mlx, window->window, image, 640, 360);
		while (i < 1000)
			i++;
		mlx_destroy_image(window->mlx, image);
		mlx_put_image_to_window(window->mlx, window->window, image, 640, 480);
		i = 0;
	}
}

int	set_mouse(int x, int y, t_window *window)
{
	window->mouse_x = x;
	return (0);
}

int	mouse_hook(int x, int y, t_window *window)
{
	printf("%d %d\n", x, y);
	if (!window->mouse_x)
		window->mouse_x = x;
	if (x + 10 < window->mouse_x)
	{
		window->player->angle += M_PI_4 / 12;
		window->mouse_x = x;
		new_engine_start(window);
		if (window->toggle_map)
			draw_small_map(window);
	}
	else if (x - 10 > window->mouse_x)
	{
		window->player->angle -= M_PI_4 / 12;
		window->mouse_x = x;
		new_engine_start(window);
		if (window->toggle_map)
			draw_small_map(window);
	}
	return (0);
}
