/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_engine_part_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:11:37 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 12:12:09 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	fix_angle(float angle)
{
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	check_borders(t_window *window)
{
	int	mx;
	int	my;
	int	mp;

	mx = (int)window->player->dir_x;
	my = (int)window->player->dir_y;
	mp = my * window->x_border + mx;
	if (mp > 0 && mp < window->x_border * window->y_border)
		return (1);
	return (0);
}
