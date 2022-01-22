/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_on_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:07:26 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/22 15:14:16 by wabathur         ###   ########.fr       */
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

void	count_ray(t_window *window, float xend, float yend, int color)
{
	float	dx;
	float	dy;
	int		l;
	int		i;

	i = 0;
	l = find_max(xend - window->player->x, yend - window->player->y);
	dx = (xend - window->player->x) / l;
	dy = (yend - window->player->y) / l;
	printf("%f %f %d\n", dx, dy, l);
	while (i < l * 50)
	{
		mlx_pixel_put(window->mlx, window->window,
			((window->player->x) * 50 + dx * i),
			((window->player->y) * 50 + dy * i), color);
		i++;
	}
}
