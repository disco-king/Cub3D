/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:56:37 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/26 13:07:52 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/*we need map size in control structure
alternative codes are added for testability on linux*/
int	key_hook(int keycode, t_window *window)
{
	// printf("keycode is %d\n", keycode);
	if ((keycode == A || keycode == A2) && window->player->x > 1
		&& window->map[(int)(window->player->y - 1.5)][(int)window->player->x] != '1')
		window->player->y -= 1;
	else if ((keycode == W || keycode == W2) && window->player->y > 1
		&& window->map[(int)window->player->y][(int)window->player->x + 1] != '1')
		window->player->x += 1;
	else if ((keycode == S || keycode == S2)
		&& window->map[(int)window->player->y][(int)window->player->x - 1] != '1')
		window->player->x -= 1;
	else if ((keycode == D || keycode == D2)
		&& window->map[(int)window->player->y + 1][(int)window->player->x] != '1')
		window->player->y += 1;
	else if (keycode == ESC)
	{
		mlx_destroy_window(window->mlx, window->window);
		exit(0);
	}
	else if (keycode != RA && keycode != LA)
	{
		return (0);
	}
	// mlx_clear_window(window->mlx, window->window);
	change_dir(window, keycode);
	new_engine_start(window);
	return (0);
}
