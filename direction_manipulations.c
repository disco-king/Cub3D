/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_manipulations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:33:35 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 16:46:52 by fmalphit         ###   ########.fr       */
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
		draw_wall(window, i);
		i++;
	}
	i = 0;
	window->player->angle += M_PI / 6;
	while (i <= 640)
	{
		window->player->angle -= M_PI / 6 / 640;
		find_end_points(window);
		draw_wall(window, 1280 - i);
		i++;
	}
}

void	change_dir(t_window *window, int keycode)
{
	if (keycode == LA || keycode == LA2)
	{	
		window->player->angle += M_PI_4 / 12;
	}
	if (keycode == RA || keycode == RA2)
	{
		window->player->angle -= M_PI_4 / 12;
	}
}
