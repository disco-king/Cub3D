/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_manipulations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:33:35 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/26 13:30:38 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_all_rays(t_window *window, int color)
{
	float	temp_angle;
	int		i;

	temp_angle = window->player->angle;
	i = 0;
	window->player->angle -= M_PI / 6;
	color = 100;
	while (i < 640)
	{
		window->player->angle += M_PI / 6 / 640;
		find_end_points(window);
		window->color = 160000;
		draw_wall(window, i);
		//count_ray(window, window->player->dir_x, window->player->dir_y, color);
		i++;
	}
	i = 0;
	window->player->angle += M_PI / 6;
	while (i <= 640)
	{
		window->player->angle -= M_PI / 6 / 640;
		find_end_points(window);
		//count_ray(window, window->player->dir_x, window->player->dir_y, color);
		window->color = 160100;
		draw_wall(window, 1280 - i);
		i++;
	}
	window->player->angle = temp_angle;
	find_end_points(window);
	window->player->angle = temp_angle;
	find_end_points(window);
}

void	change_dir(t_window *window, int keycode)
{
	if (keycode == W || keycode == S
		|| keycode == A || keycode == D)
		find_end_points(window);
	if (keycode == LA)
	{	
		//draw_all_rays(window, 649);
		window->player->angle -= M_PI_4 / 12;
		if (window->player->angle == -M_PI * 2)
			window->player->angle = 0;
		find_end_points(window);
		//draw_all_rays(window, 160000);
	}
	if (keycode == RA)
	{
		//draw_all_rays(window, 649);
		window->player->angle += M_PI_4 / 12;
		if (window->player->angle == M_PI * 2)
			window->player->angle = 0;
		find_end_points(window);
		//draw_all_rays(window, 160000);
	}
}
