#include "raycast.h"

void	choose_color(t_window *window)
{
	if (window->side == 0)
	{
		if (window->player->y > window->player->dir_y)
			window->color += 200;
	}
	if (window->side == 1)
	{
		if (window->player->x > window->player->dir_x)
			window->color -= 200;
	}
}

float	fix_angle(float angle)
{
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	check_borders(t_window *window)
{
	int	mx;
	int	my;
	int	mp;

	mx = (int)window->player->dir_x;
	my = (int)window->player->dir_y;
	mp = my * window->x_border + mx;
	if (mp > 0 && mp < window->x_border * window->y_border)
		return (1);
	return (0);
}

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
	int		i;
	static int img_turn;

	i = 0;
	step_x = 0;
	step_y = 0;
	hit = 0;
	r = window->player->angle;
	r += M_PI / 6;
	r = fix_angle(r);
	x = 0;
	distance_vert = 100000;
	distance_hor = 100000;
	window->img->cur_img = window->img->img[img_turn];
	window->img->cur_addr = window->img->addr[img_turn];
	color_window(window);
	while (x < 1280)
	{
		distance_vert = 100000;
		distance_hor = 100000;
		window->color = 160000;
		user_tan = tan(r);
		window->side = 0;
		if (cos(r) > 0.001)
		{
			window->player->dir_x = (int)window->player->x + 1;
			window->player->dir_y = (window->player->x - window->player->dir_x)
				* user_tan + window->player->y;
			step_x = 1;
			step_y = -step_x * user_tan;
		}
		else if (cos(r) < -0.001)
		{
			window->player->dir_x = (int)window->player->x - 0.0001;
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
		i = 0;
		while (!hit && i <= window->x_border)
		{
			if (check_borders(window))
				if (window->player->dir_x < 0 || window->player->dir_y < 0
					|| window->map[(int)window->player->dir_y][(int)window->player->dir_x] == '1')
				{
					distance_vert = cos(r) * (window->player->dir_x - window->player->x)
						- sin(r) * (window->player->dir_y - window->player->y);
					hit = 1;
				}
			if (!hit)
			{
				i++;
				window->player->dir_x += step_x;
				window->player->dir_y += step_y;
			}
		}
		i = 0;
		v_x = window->player->dir_x;
		v_y = window->player->dir_y;
		user_tan = 1 / user_tan;
		hit = 0;
		if (sin(r) > 0.001)
		{
			window->player->dir_y = (int)window->player->y - 0.0001;
			window->player->dir_x = (window->player->y - window->player->dir_y)
				* user_tan + window->player->x;
			step_y = -1;
			step_x = -step_y * user_tan;
		}
		else if (sin(r) < -0.001)
		{
			window->player->dir_y = (int)window->player->y + 1;
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
		i = 0;
		while (!hit && i <= window->y_border)
		{
			if (check_borders(window))
				if (window->player->dir_x < 0 || window->player->dir_y < 0
					|| window->map[(int)window->player->dir_y][(int)window->player->dir_x] == '1')
				{
					distance_hor = cos(r) * (window->player->dir_x - window->player->x)
						- sin(r) * (window->player->dir_y - window->player->y);
					hit = 1;
				}
			if (!hit)
			{
				i++;
				window->player->dir_x += step_x;
				window->player->dir_y += step_y;
			}
		}

		if (distance_vert < distance_hor)
		{
			window->player->dir_x = v_x;
			window->player->dir_y = v_y;
			window->distance = distance_vert;
			window->color = 160100;
			window->side = 1;
		}
		else
			window->distance = distance_hor;
		window->distance = cos(r - window->player->angle) * window->distance;
		draw_wall(window, x);
		x += 1;
		r -= M_PI / 3 / 1280;
		r = fix_angle(r);
		hit = 0;
	}
	img_turn = (img_turn + 1) % 2;
	mlx_put_image_to_window(window->mlx, window->window, window->img->cur_img, 0, 0);
}
