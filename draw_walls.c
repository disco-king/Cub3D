/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:14:33 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/25 15:16:39 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	count_distance(t_window *window)
{
	float	distance;
	float	dx;
	float	dy;

	dx = window->player->dir_x - window->player->x;
	dy = window->player->dir_y - window->player->y;
	distance = sqrtf(dx * dx + dy * dy);
	return (distance);
}


void	my_mlx_put_pixel()
{
	
}


int	count_color(t_window *window, t_data *image)
{
	int	width;
	int	height;
	
	image->img = mlx_xpm_file_to_image(window->mlx, "1.xpm", &width, &height);
	
}

void	draw_wall(t_window *window)
{
	float	wall_height;
	float	distance;
	t_data	image;
	int		width;
	int		height;

	width = 1;
	distance = count_distance(window) * cos(window->player->angle);
	wall_height = height / distance;
	printf("wall height is %f %d\n", wall_height, height);
	mlx_put_image_to_window(window->mlx, window->window, image.img, window->player->dir_x, wall_height);
}
