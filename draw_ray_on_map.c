/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_on_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:07:26 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/25 13:28:54 by wabathur         ###   ########.fr       */
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
	if (window->map[(int)(((window->player->y + 0.5)  + dy * i))]
			[(int)(((window->player->x + 0.5)+ dx * i))] == '1')
		return (1);
	return (0);
}

void	find_end_points(t_window *window)
{
	int	i;

	i = 0;
	while (1)
	{
		window->player->dir_x = window->player->x
			+ i * cosf(window->player->angle);
		window->player->dir_y = window->player->y
			+ i * sinf(window->player->angle);
		if (!window->map[(int)window->player->dir_y]
			[(int)window->player->dir_x]
			|| window->map[(int)window->player->dir_y]
			[(int)window->player->dir_x] == '1')
			break ;
		i++;
	}
}

void	count_ray(t_window *window, float xend, float yend, int color)
{
	float	dx;
	float	dy;
	float	l;
	int		i;

	i = 0;
	//printf("here %f %f\n", window->player->dir_x, window->player->dir_y);
	//printf("distance %f %f\n", xend - window->player->x, yend - window->player->y);
	l = find_max(xend - window->player->x, yend - window->player->y);
	dx = (xend - window->player->x) / l;
	dy = (yend - window->player->y) / l;
	printf("%d\n",color);
	//printf("%f %f\n", dx, dy);
	l = roundf(l);
	while (1)
	{
		if (l == 0)
			break ;
		// mlx_pixel_put(window->mlx, window->window,
		// 	((window->player->x + 0.50) * 50 + dx * i),
		// 	((window->player->y + 0.50) * 50 + dy * i), color);
		if (count_break(window, i, dx, dy))
			break ;
		i++;
	}
	draw_wall(window);
}
