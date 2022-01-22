/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_manipulations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:33:35 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/22 18:27:16 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	change_dir(t_window *window, int keycode)
{
	if (keycode == W)
		window->player->dir_y += 1;
	if (keycode == A)
		window->player->dir_x -= 1;
	if (keycode == S)
		window->player->dir_y -= 1;
	if (keycode == D)
		window->player->dir_x += 1;
	if (keycode == LA)
	{	
		//window->player->angle = M_PI;
		window->player->dir_x = window->player->dir_x
			- window->player->angle;
		window->player->dir_y = window->player->dir_y
			- window->player->angle;
	}
	if (keycode == RA)
	{
		//window->player->angle = M_PI;
		window->player->dir_x = window->player->dir_x
			+ window->player->angle;
		window->player->dir_y = window->player->dir_y
			+ window->player->angle;
	}
}
