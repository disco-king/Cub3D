/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:14:33 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/26 13:16:59 by wabathur         ###   ########.fr       */
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


// void	my_mlx_put_pixel()
// {
	
// }


int	count_color(t_window *window, t_data *image)
{
	int	width;
	int	height;
	
	image->img = mlx_xpm_file_to_image(window->mlx, "1.xpm", &width, &height);
	return (0);
}

void	calc_pixel(t_window *window, int wall_height, int height, int x)
{
	int	draw_start;
	int	draw_end;
	int	j;
	int	i;

	i = 0;
	j = 0;
	//printf("wall height %d height %d %d\n", wall_height, height, x);
	draw_start = -wall_height / 2 + height / 2;
	draw_end = wall_height / 2 + height / 2;
	printf("start %d end %d\n", draw_start, draw_end);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= height)
		draw_end = height - 1;
	printf("draw start %d draw end %d x is %d\n", draw_start, draw_end, x);
	while (draw_start < draw_end)
	{
		// while (j < 100)
		// {
			//printf("draw start %d draw end %d\n", draw_start, draw_end);
			//printf("pix %d %d\n", x, draw_start);
			mlx_pixel_put(window->mlx, window->window, x, draw_start, window->color);
			//pix_to_img(window->img, x, draw_start, window->color);
		// 	j++;
		// }
		j = 0;
		draw_start++;
	}
	//usleep(10000);
}


void	draw_wall(t_window *window, int x)
{
	float	wall_height;
	float	distance;
	//t_data	image;
	int		width;
	int		height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	width = 1;
	height = 720;
	//printf("here %f\n", window->distance);
	wall_height = height / window->distance;
	if (wall_height < 0)
		wall_height = - wall_height;
	calc_pixel(window, wall_height, height, x);
	// while (i++ < wall_height)
	// {
	// 	//while (j++ <= 50)
	// 		mlx_pixel_put(window->mlx, window->window, window->player->dir_y * 50 + i, window->player->dir_x, 160000);
	// 	j = 0;
	// }
	//printf("wall height is %f %d\n", wall_height, height);
	//mlx_put_image_to_window(window->mlx, window->window, image.img, window->player->dir_x, wall_height);
}
