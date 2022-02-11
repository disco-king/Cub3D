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

float step_dir(int code)
{
	float ret;

	if(code == A || code == A2)
		ret = 1.570796;
	else if(code == S || code == S2)
		ret = 3.141592;
	else if(code == D || code == D2)
		ret = 4.712388;
	else
		ret = 0.0;
	return(ret);
}

void get_move(t_player *player, int move[2], int code)//set move values to one of four options
{
	if(code == LA || code == RA)
	{
		move[0] = 0;
		move[1] = 0;
		return ;
	}
	float angle = fix_angle(player->angle + step_dir(code));
	printf("checking angle %f\n", angle);
	if((angle >= 1.18 && angle < 1.96)
		|| (angle >= 4.32 && angle < 5.11))//this series of ifs determines x value
		move[0] = 0;
	else if(angle >= 1.96 && angle < 4.34)
		move[0] = -1;
	else
		move[0] = 1;

	if(angle >= 0.39 && angle < 2.75)//this series of ifs determines y value
		move[1] = -1;
	else if(angle >= 3.53 && angle < 5.89)
		move[1] = 1;
	else
		move[1] = 0;
	
	printf("player angle %f\nmove angle %f\nx move %d y move %d\n",
		player->angle, angle, move[0], move[1]);
}

/*we need map size in control structure
alternative codes are added for testability on linux*/
int	key_hook(int keycode, t_window *window)
{
	int move[2];//x and y of the point we'll stand at after the move
	printf("keycode is %d\n", keycode);
	mlx_clear_window(window->mlx, window->window);
	if (keycode == ESC)
	{
		mlx_destroy_window(window->mlx, window->window);
		exit(0);
	}
	if (keycode != RA && keycode != LA &&
		keycode != A && keycode != W &&
		keycode != S && keycode != D &&
		keycode != A2 && keycode != W2 &&
		keycode != S2 && keycode != D2)
		return (0);
	change_dir(window, keycode);
	get_move(window->player, move, keycode);
	if(window->map[(int)(window->player->y + move[1])][(int)(window->player->x + move[0])] != '0' &&
		window->map[(int)(window->player->y + move[1])][(int)(window->player->x + move[0])] != 'N')
		return(0);
	window->player->y += move[1];
	window->player->x += move[0];
	new_engine_start(window);
	return (0);
}
