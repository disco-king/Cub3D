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

void get_move(t_player *player, float move[2], int code)//set move values to one of four options
{
	if(code == LA || code == RA)
	{
		move[0] = 0;
		move[1] = 0;
		return ;
	}
	float angle = fix_angle(player->angle + step_dir(code));
	if((angle >= 1.18 && angle < 1.96)
		|| (angle >= 4.32 && angle < 5.11))//this series of ifs determines x value
		move[0] = 0;
	else if(angle >= 1.96 && angle < 4.34)
		move[0] = -STEP;
	else
		move[0] = STEP;

	if(angle >= 0.39 && angle < 2.75)//this series of ifs determines y value
		move[1] = -STEP;
	else if(angle >= 3.53 && angle < 5.89)
		move[1] = STEP;
	else
		move[1] = 0;
	// printf("effective angle by %d is %f, x %f y %f\n", code, angle, move[0], move[1]);
}

// int check_move(int p_x, int p_y, float *move, char **map)
// {
// 	if(!strchr(STEPPABLE, map[(int)(p_y + move[1])][(int)(p_x + move[0])])
// 		|| )
// 		return(1);
// 	return(0);
// }

/*we need map size in control structure
alternative codes are added for testability on linux*/
int	key_hook(int keycode, t_window *window)
{
 	float move[2];//x and y of the point we'll stand at after the move
	if (keycode == ESC)
	{
		mlx_destroy_window(window->mlx, window->window);
		exit(0);
	}
	if (keycode != RA && keycode != LA
		&& keycode != A && keycode != W
		&& keycode != S && keycode != D
		&& keycode != A2 && keycode != W2
		&& keycode != S2 && keycode != D2
		&& keycode != M)
		return (0);
	if (keycode == M)
	{
		if (!window->toggle_map)
		{
			draw_small_map(window);
			window->toggle_map = 1;
			return (0);
		}
		else
		{
			window->toggle_map = 0;
			new_engine_start(window);
			return (0);
		}
	}
	change_dir(window, keycode);
	window->player->angle = fix_angle(window->player->angle);
	get_move(window->player, move, keycode);
	printf("potential move x %f y %f - ", window->player->x + move[0], window->player->y + move[1]);
	if(window->map[(int)(window->player->y + move[1])][(int)(window->player->x + move[0])] != '0' &&
		window->map[(int)(window->player->y + move[1])][(int)(window->player->x + move[0])] != 'P')
	{
		printf("nope!\n");
		return(0);
	}
	printf("yup!\n");
	window->map[(int)window->player->y][(int)window->player->x] = '0';
	window->player->y += move[1];
	window->player->x += move[0];
	window->map[(int)window->player->y][(int)window->player->x] = 'P';
	new_engine_start(window);
	return (0);
}
