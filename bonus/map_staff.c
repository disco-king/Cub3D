/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_staff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:49:19 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 17:52:07 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycast.h"

void	put_hero(t_window *window, int x, int y)
{
	void	*map_image;
	int		width;
	int		height;

	map_image = mlx_xpm_file_to_image(window->mlx, "./hero_cub.xpm",
			&height, &width);
	if (!map_image)
		return ;
	mlx_put_image_to_window(window->mlx, window->window,
		map_image, x * 16, y * 16);
}

void	set_coordinates(t_window *window, int *x, int *y)
{
	*x = (int)window->player->x - 3;
	*y = (int)window->player->y - 3;
	if (*x < 0)
		*x = 0;
	if (*y < 0)
		*y = 0;
}

void	draw_surroundings(t_window *window, int x_map,
				int y_map, void *map_image)
{
	int		x;
	int		y;

	set_coordinates(window, &x, &y);
	while (y < window->player->y + 3 && y < window->y_border)
	{
		while (x < window->player->x + 3
			&& x < window->x_border)
		{
			if (window->map[y][x] == '1')
				mlx_put_image_to_window(window->mlx, window->window,
					map_image, x_map * 16, y_map * 16);
			else if (window->map[y][x] == 'P')
				put_hero(window, x_map, y_map);
			x_map++;
			x++;
		}
		x = (int)window->player->x - 3;
		x_map = 70;
		y_map++;
		y++;
	}
}

void	draw_small_map(t_window *window)
{
	void	*map_image;
	int		height;
	int		width;
	int		x_map;
	int		y_map;

	x_map = 70;
	y_map = 0;
	map_image = mlx_xpm_file_to_image(window->mlx, "./small_wall.xpm",
			&height, &width);
	if (!map_image)
		return ;
	draw_surroundings(window, x_map, y_map, map_image);
}
