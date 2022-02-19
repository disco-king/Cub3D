/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:28:15 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 16:49:30 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	calculate_distance(t_window *window, float r, float distance)
{
	int	i;

	i = 0;
	while (!window->hit && i <= window->x_border)
	{
		if (check_borders(window))
		{
			if (window->player->dir_x < 0 || window->player->dir_y < 0
				|| window->map[(int)window->player->dir_y]
				[(int)window->player->dir_x] == '1')
			{
				distance = cos(r) * (window->player->dir_x - window->player->x)
					- sin(r) * (window->player->dir_y - window->player->y);
				window->hit = 1;
			}
		}
		if (!window->hit)
		{
			i++;
			window->player->dir_x += window->step_x;
			window->player->dir_y += window->step_y;
		}
	}
	return (distance);
}

void	calc_vert_distance(t_window *window, float user_tan, float r)
{
	if (cos(r) > 0.001)
	{
		window->player->dir_x = (int)window->player->x + 1;
		window->player->dir_y = (window->player->x - window->player->dir_x)
			* user_tan + window->player->y;
		window->step_x = 1;
		window->step_y = -window->step_x * user_tan;
	}
	else if (cos(r) < -0.001)
	{
		window->player->dir_x = (int)window->player->x - 0.0001;
		window->player->dir_y = (window->player->x - window->player->dir_x)
			* user_tan + window->player->y;
		window->step_x = -1;
		window->step_y = -window->step_x * user_tan;
	}
	else
	{
		window->player->dir_x = window->player->x;
		window->player->dir_y = window->player->y;
		window->hit = 1;
	}
	window->distance_vert
		= calculate_distance(window, r, window->distance_vert);
}

void	calc_hor_distance(t_window *window, float user_tan, float r)
{
	if (sin(r) > 0.001)
	{
		window->player->dir_y = (int)window->player->y - 0.0001;
		window->player->dir_x = (window->player->y - window->player->dir_y)
			* user_tan + window->player->x;
		window->step_y = -1;
		window->step_x = -window->step_y * user_tan;
	}
	else if (sin(r) < -0.001)
	{
		window->player->dir_y = (int)window->player->y + 1;
		window->player->dir_x = (window->player->y - window->player->dir_y)
			* user_tan + window->player->x;
		window->step_y = 1;
		window->step_x = -window->step_y * user_tan;
	}
	else
	{
		window->player->dir_x = window->player->x;
		window->player->dir_y = window->player->y;
		window->hit = 1;
	}
	window->distance_hor = calculate_distance(window, r, window->distance_hor);
}

void	do_staff(t_window *window, float user_tan, float r, int x)
{
	window->distance_vert = 100000;
	window->distance_hor = 100000;
	window->color = 160000;
	user_tan = tan(r);
	window->side = 0;
	calc_vert_distance(window, user_tan, r);
	calculate_distance(window, r, window->distance_vert);
	window->v_x = window->player->dir_x;
	window->v_y = window->player->dir_y;
	user_tan = 1 / user_tan;
	window->hit = 0;
	calc_hor_distance(window, user_tan, r);
	if (window->distance_vert < window->distance_hor)
	{
		window->player->dir_x = window->v_x;
		window->player->dir_y = window->v_y;
		window->distance = window->distance_vert;
		window->color = 160100;
		window->side = 1;
	}
	else
		window->distance = window->distance_hor;
	window->distance = cos(r - window->player->angle) * window->distance;
	draw_wall(window, x);
	window->hit = 0;
}

void	new_engine_start(t_window *window)
{
	float		r;
	float		user_tan;
	int			x;
	static int	img_turn;

	window->step_x = 0;
	window->step_y = 0;
	window->hit = 0;
	r = window->player->angle;
	r = fix_angle(r + M_PI / 6);
	x = 0;
	window->img->cur_img = window->img->img[img_turn];
	window->img->cur_addr = window->img->addr[img_turn];
	mlx_clear_window(window->mlx, window->window);
	color_window(window);
	user_tan = 0;
	while (x < 1280)
	{
		do_staff(window, user_tan, r, x);
		x += 1;
		r -= M_PI / 3 / 1280;
		r = fix_angle(r);
	}
	img_turn = (img_turn + 1) % 2;
	mlx_put_image_to_window(window->mlx, window->window,
		window->img->cur_img, 0, 0);
}
