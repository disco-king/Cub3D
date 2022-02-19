/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_on_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:07:26 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 11:39:54 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	find_max(float n1, float n2)
{
	if (n1 < 0)
		n1 = n1 * (-1);
	if (n2 < 0)
		n2 = n2 * (-1);
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	count_break(t_window *window, int i, float dx, float dy)
{
	if (window->map[(int)(((window->player->y + 0.5) + dy * i))]
			[(int)(((window->player->x + 0.5) + dx * i))] == '1')
		return (1);
	return (0);
}

void	vert_points(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->y_border)
	{
		window->player->dir_x = window->player->x
			+ 1 * i;
		window->player->dir_y = window->player->y
			+ i * sin(window->player->angle);
		if (check_borders(window))
			if (window->player->dir_x < 0 || window->player->dir_y < 0
				|| !window->map[(int)window->player->dir_y]
				[(int)window->player->dir_x]
				|| window->map[(int)window->player->dir_y]
				[(int)window->player->dir_x] == '1')
				break ;
		i++;
	}
	window->distance = count_distance(window);
}

void	hor_points(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->x_border)
	{
		window->player->dir_x = window->player->x
			+ i * cos(window->player->angle);
		window->player->dir_y = window->player->y
			- 1 * i;
		if (check_borders(window))
			if (window->player->dir_x < 0 || window->player->dir_y < 0
				|| !window->map[(int)window->player->dir_y]
				[(int)window->player->dir_x]
				|| window->map[(int)window->player->dir_y]
				[(int)window->player->dir_x] == '1')
				break ;
		i++;
	}
	window->distance = count_distance(window);
}

void	find_end_points(t_window *window)
{
	float	temp_dir_x;
	float	temp_dir_y;
	float	current_dist;

	vert_points(window);
	temp_dir_x = window->player->dir_x;
	temp_dir_y = window->player->dir_y;
	current_dist = window->distance;
	hor_points(window);
	if (current_dist < window->distance)
	{
		window->player->dir_x = temp_dir_x;
		window->player->dir_y = temp_dir_y;
		window->distance = current_dist;
		window->color = 160000;
	}
	else
		window->color = 160100;
}
