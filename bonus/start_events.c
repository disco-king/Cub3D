/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:42:31 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 17:52:18 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycast.h"

void	color_window(t_window *window)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 717 && y++ <= 360 + window->offset)
	{
		while (x++ <= 1280)
			pix_to_img(window->img, x, y,
				window->params->c_col);
		x = 0;
	}
	while (y++ <= 717)
	{
		while (x++ <= 1280)
			pix_to_img(window->img, x, y,
				window->params->f_col);
		x = 0;
	}
}

void	choose_start_dir(t_window *window, char c)
{
	if (c == 'N')
		window->player->angle = M_PI_2;
	if (c == 'E')
		window->player->angle = 0;
	if (c == 'W')
		window->player->angle = M_PI;
	if (c == 'S')
		window->player->angle = M_PI + M_PI_2;
}

void	find_start_pos_and_dir(char **map, t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	window->player->x = -1;
	window->player->y = -1;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && (map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S'))
			{
				window->player->start_direction = map[i][j];
				window->player->x = (float)(j + 0.1);
				window->player->y = (float)(i + 0.1);
				choose_start_dir(window, map[i][j]);
				window->map[i][j] = 'P';
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

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				scale_map(i * 50, j * 50, window, 80000);
			if (map[i][j] == 'N')
			{
				scale_map(i * 50, j * 50, window, 160000);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	init_window(t_window *window, char **map)
{
	t_data	img;
	void	*image1;
	void	*image2;

	window->mlx = mlx_init();
	window->img = &img;
	get_new_image(&image1, &image2, window);
	img.img[0] = image1;
	img.img[1] = image2;
	window->toggle_map = 0;
	window->mouse_x = 0;
	window->mouse_y = 0;
	window->offset = 0;
	window->window = mlx_new_window(window->mlx, 1280, 720, "cub3d");
	find_start_pos_and_dir(map, window);
	if (window->player->x <= 0 || window->player->y <= 0)
	{
		write(1, "No player\n", 10);
		exit (0);
	}
	get_texture(window);
	new_engine_start(window);
	mlx_hook(window->window, 2, 1L << 0, key_hook, window);
	mlx_hook(window->window, 6, 1L << 6, mouse_hook, window);
	mlx_hook(window->window, 17, 1L << 17, close_mouse, window);
	mlx_loop(window->mlx);
}
