#include "raycast.h"

void	new_engine_start(t_window *window)
{
	float	r;
	float	user_tan;
	float	step_x;
	float	step_y;
	float	distance_vert;
	float	distance_hor;
	float	v_x;
	float	v_y;
	int		hit;
	int		x;

	step_x = 0;
	step_y = 0;
	hit = 0;
	r = window->player->angle;
	r += M_PI / 6;
	x = 0;
	distance_vert = 10000;
	distance_hor = 10000;
	while (x < 1280)
	{
		printf("x is %d", x);
		user_tan = tanf(r);
		if (cosf(r) > 0)
		{
			window->player->dir_x = window->player->x + 1;
			window->player->dir_y = (window->player->x - window->player->dir_x)
				* user_tan + window->player->y;
			step_x += 1;
			step_y = -step_x * user_tan;
		}
		else if (cosf(r) < 0)
		{
			window->player->dir_x = window->player->x;
			window->player->dir_y = (window->player->x - window->player->dir_x)
				* user_tan + window->player->y;
			step_x = -1;
			step_y = -step_x * user_tan;
		}
		else
		{
			window->player->dir_x = window->player->x;
			window->player->dir_y = window->player->y;
			hit = 1;
		}
		while (!hit)
		{
			if (window->map[(int)window->player->dir_y][(int)window->player->dir_x] == '1'
				|| window->map[(int)window->player->dir_y][(int)window->player->dir_x])
			{
				distance_vert = cosf(r) * (window->player->dir_x - window->player->x)
					- sinf(r) * (window->player->dir_y - window->player->y);
				hit = 1;
			}
			else
			{
				window->player->dir_x += step_x;
				window->player->dir_y += step_y;
			}
		}
		v_x = window->player->dir_x;
		v_y = window->player->dir_y;
		user_tan = 1 / user_tan;
		hit = 0;
		printf("distance vert is %f\n",distance_vert);
		if (sinf(r) > 0)
		{
			window->player->dir_y = window->player->y;
			window->player->dir_x = (window->player->y - window->player->dir_y)
				* user_tan + window->player->x;
			step_y = -1;
			step_x = -step_y * user_tan;
		}
		else if (sinf(r) < 0)
		{
			window->player->dir_y = window->player->y + 1;
			window->player->dir_x = (window->player->y - window->player->dir_y)
				* user_tan + window->player->x;
			step_y = 1;
			step_x = -step_y * user_tan;
		}
		else
		{
			window->player->dir_x = window->player->x;
			window->player->dir_y = window->player->y;
			hit = 1;
		}
		while (!hit)
		{
			if (window->map[(int)window->player->dir_y][(int)window->player->dir_x] == '1'
			|| window->map[(int)window->player->dir_y][(int)window->player->dir_x])
			{
				distance_hor = cosf(r) * (window->player->dir_x - window->player->x)
					- sinf(r) * (window->player->dir_y - window->player->y);
				hit = 1;
			}
			else
			{
				window->player->dir_x += step_x;
				window->player->dir_y += step_y;
			}
		}
		if (distance_vert < distance_hor)
		{
			window->player->dir_x = v_x;
			window->player->dir_y = v_y;
			distance_hor = distance_vert;
		}
		window->player->angle = r;
		printf("distance hor is %f\n",distance_hor);
		draw_wall(window, x);
		x += 1;
		r -= M_PI / 6 / 720;
	}
}