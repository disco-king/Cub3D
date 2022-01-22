/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:52:26 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/22 13:59:25 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	scale_map(int i, int j, t_window *window, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= 50)
	{
		while (x <= 50)
		{
			mlx_pixel_put(window->mlx, window->window, j + x, i + y, color);
			x++;
		}
		x = 0;
		y++;
	}
}
