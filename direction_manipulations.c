/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_manipulations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:33:35 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/23 14:10:05 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	change_dir(t_window *window, int keycode)
{
	if (keycode == W || keycode == S
		|| keycode == A || keycode == D)
		find_end_points(window);
	if (keycode == LA)
	{	
		window->player->angle -= M_PI_4 / 12;
		if (window->player->angle == -M_PI * 2)
			window->player->angle = 0;
		find_end_points(window);
	}
	if (keycode == RA)
	{
		window->player->angle += M_PI_4 / 12;
		if (window->player->angle == M_PI * 2)
			window->player->angle = 0;
		find_end_points(window);
	}
}
