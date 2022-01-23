/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_manipulations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:33:35 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/23 15:45:41 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_all_rays(t_window *window, int color)
{
	float	temp_angle;
	int		i;

	temp_angle = window->player->angle;
	i = 1;
	window->player->angle -= M_PI / 3;
	while (i < 512)
	{
		window->player->angle += M_PI / 3 / 512;
		find_end_points(window);
		count_ray(window, window->player->dir_x, window->player->dir_y, color);
		i++;
	}
	i = 1;
	window->player->angle += M_PI / 3;
	while (i < 512)
	{
		window->player->angle -= M_PI / 3 / 512;
		find_end_points(window);
		count_ray(window, window->player->dir_x, window->player->dir_y, color);
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
		draw_all_rays(window, 649);
		window->player->angle -= M_PI_4 / 12;
		if (window->player->angle == -M_PI * 2)
			window->player->angle = 0;
		find_end_points(window);
		draw_all_rays(window, 160000);
	}
	if (keycode == RA)
	{
		draw_all_rays(window, 649);
		window->player->angle += M_PI_4 / 12;
		if (window->player->angle == M_PI * 2)
			window->player->angle = 0;
		find_end_points(window);
		draw_all_rays(window, 160000);
	}

}
