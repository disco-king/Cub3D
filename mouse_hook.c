#include "raycast.h"

int	set_mouse(int x, int y, t_window *window)
{
	window->mouse_x = 360;
	return (0);
}

void	get_x(t_window *window, int x, int y)
{
	if (x + 10 < window->mouse_x && x < 1280 && x >= 0 && y <= 720 && y >= 0)
	{
		window->player->angle += M_PI_4 / 12;
		window->mouse_x = x;
	}
	else if (x - 10 > window->mouse_x && x <= 1280
		&& x >= 0 && y <= 720 && y >= 0)
	{
		window->player->angle -= M_PI_4 / 12;
		window->mouse_x = x;
	}
}

void	get_y(t_window *window, int x, int y)
{
	if (y + 20 < window->mouse_y && window->offset < 300
		&& x <= 1280 && x >= 0 && y <= 720 && y >= 0)
	{
		window->offset += 40;
		window->mouse_y = y;
	}
	else if (y - 20 > window->mouse_y && window->offset > -300
		&& x <= 1280 && x >= 0 && y <= 720 && y >= 0)
	{
		window->offset -= 40;
		window->mouse_y = y;
	}
}

int	mouse_hook(int x, int y, t_window *window)
{
	int	temp_offset;

	temp_offset = window->offset;
	if (!window->mouse_x)
	{
		window->mouse_x = x;
		window->mouse_y = y;
	}
	window->offset = 0;
	get_x(window, x, y);
	window->offset = temp_offset;
	get_y(window, x, y);
	new_engine_start(window);
	if (window->toggle_map)
		draw_small_map(window);
	return (0);
}
