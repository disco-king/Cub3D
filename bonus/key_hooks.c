/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:56:37 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 12:29:51 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycast.h"

int	close_mouse(void)
{
	exit(0);
}

float	border_val(float value)
{
	int	i;

	i = value * 10;
	if (i % 10 == 9)
		return (value + 1);
	if (i % 10 == 0)
		return (value - 1);
	return (value);
}

int	check_move(float p_x, float p_y, float *move, char **map)
{
	if (map[(int)(p_y + 0.1 + move[1])][(int)(p_x + 0.1 + move[0])] == '1' ||
		map[(int)border_val(p_y + move[1])]
			[(int)border_val(p_x + move[0])] == '1' ||
		map[(int)(p_y + move[1])][(int)border_val(p_x + move[0])] == '1' ||
		map[(int)border_val(p_y + move[1])][(int)(p_x + move[0])] == '1')
	{
		return (1);
	}
	return (0);
}

int	check_keycode(t_window *window, int keycode)
{
	if (keycode == M || keycode == M2)
	{
		if (!window->toggle_map)
		{
			window->toggle_map = 1;
			draw_small_map(window);
		}
		else
		{
			window->toggle_map = 0;
			redraw(window);
		}
	}
	if (keycode != RA && keycode != LA
		&& keycode != A && keycode != W
		&& keycode != S && keycode != D
		&& keycode != A2 && keycode != W2
		&& keycode != S2 && keycode != D2)
		return (0);
	return (1);
}

int	key_hook(int keycode, t_window *window)
{
	float	move[6];

	if (keycode == ESC)
	{
		mlx_destroy_window(window->mlx, window->window);
		exit(0);
	}
	if (!check_keycode(window, keycode))
		return (0);
	change_dir(window, keycode);
	window->player->angle = fix_angle(window->player->angle);
	get_move(window->player, move, keycode);
	if (check_move(window->player->x, window->player->y, move, window->map))
		return (0);
	window->map[(int)window->player->y][(int)window->player->x] = '0';
	window->player->y += move[1];
	window->player->x += move[0];
	if (window->map[(int)window->player->y][(int)window->player->x] != '1')
		window->map[(int)window->player->y][(int)window->player->x] = 'P';
	redraw(window);
	if (window->toggle_map)
		draw_small_map(window);
	return (0);
}
