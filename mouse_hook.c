#include "raycast.h"

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
	}
	else if (x - 10 > window->mouse_x)
	{
		window->player->angle -= M_PI_4 / 12;
		window->mouse_x = x;
		new_engine_start(window);
	}
	return (0);
}