/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:56:37 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/23 14:04:24 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/*we need map size in control structure*/
int	key_hook(int keycode, t_window *window)
{
	count_ray(window, window->player->dir_x, window->player->dir_y, 649);
	scale_map(window->player->y * 50, window->player->x * 50, window, 649);
	if (keycode == A && window->player->x > 1
		&& window->map[window->player->y][window->player->x - 1] != '1')
		window->player->x -= 1;
	else if (keycode == W && window->player->y > 1
		&& window->map[window->player->y - 1][window->player->x] != '1')
		window->player->y -= 1;
	else if (keycode == S
		&& window->map[window->player->y + 1][window->player->x] != '1')
		window->player->y += 1;
	else if (keycode == D
		&& window->map[window->player->y][window->player->x + 1] != '1')
		window->player->x += 1;
	else if (keycode == ESC)
	{
		mlx_destroy_window(window->mlx, window->window);
		exit(0);
	}	
	else if (keycode != RA && keycode != LA)
	{
		count_ray(window, window->player->dir_x, window->player->dir_y, 160000);
		scale_map(window->player->y * 50,
			window->player->x * 50, window, 160000);
		return (0);
	}
	change_dir(window, keycode);
	count_ray(window, window->player->dir_x, window->player->dir_y, 160000);
	scale_map(window->player->y * 50, window->player->x * 50, window, 160000);
	return (0);
}
