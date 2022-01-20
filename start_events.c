/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:42:31 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/20 19:03:39 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	color_window(t_window *window)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y++ <= 360)
	{
		while (x++ <= 1280)
			mlx_pixel_put(window->mlx, window->window,
				x, y, window->ceiling_color);
		x = 0;
	}
	while (y++ <= 720)
	{
		while (x++ <= 1280)
			mlx_pixel_put(window->mlx, window->window,
				x, y, window->floor_color);
		x = 0;
	}
}

void	find_start_pos_and_dir(char **map, t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0')
			{
				window->player->start_direction = map[i][j];
				window->player->x = j;
				window->player->y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	draw_big_map(t_window *window, char **map)
{
	int		i;
	int		j;
	t_map	map_s;

	i = 0;
	j = 0;
	map_s.x = 0;
	map_s.y = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				mlx_pixel_put(window->mlx, window->window, j, i, 10000);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	init_window(t_window *window, char **map)
{
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, 1280, 720, "window");
	window->floor_color = 1021;
	window->ceiling_color = 649;
	write (1, "shit\n", 5);
	color_window(window);
	draw_big_map(window, map);
	mlx_loop(window->mlx);
}
