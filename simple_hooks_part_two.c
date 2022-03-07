/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_hooks_part_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:06:13 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 12:07:38 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	step_dir(int code)
{
	float	ret;

	if (code == A || code == A2)
		ret = M_PI_2;
	else if (code == S || code == S2)
		ret = M_PI;
	else if (code == D || code == D2)
		ret = M_PI + M_PI_2;
	else
		ret = 0.0;
	return (ret);
}

void	get_move_two(float angle, float move[2])
{
	if (angle >= PI_16 + PI_8 * 12 || angle < PI_16 + PI_8 * 3)
	{
		if (angle >= PI_16 + PI_8 * 13 || angle < PI_16 + PI_8 * 2)
			move[0] = STEP * 2;
		else
			move[0] = STEP;
	}
	if (angle >= PI_16 + PI_8 * 4 && angle < PI_16 + PI_8 * 11)
	{
		if (angle >= PI_16 + PI_8 * 5 && angle < PI_16 + PI_8 * 10)
			move[0] = STEP * -2;
		else
			move[0] = -STEP;
	}
}

void	get_move(t_player *player, float move[2], int code)
{
	float	angle;

	move[0] = 0;
	move[1] = 0;
	if (code == LA || code == RA
		|| code == LA2 || code == RA2)
		return ;
	angle = fix_angle(player->angle + step_dir(code));
	if (angle >= PI_16 && angle < PI_16 + PI_8 * 7)
	{
		if (angle >= PI_16 + PI_8 && angle < PI_16 + PI_8 * 6)
			move[1] = STEP * -2;
		else
			move[1] = -STEP;
	}
	if (angle >= PI_16 + M_PI && angle < PI_16 + PI_8 * 15)
	{
		if (angle >= PI_16 + PI_8 * 9 && angle < PI_16 + PI_8 * 14)
			move[1] = STEP * 2;
		else
			move[1] = STEP;
	}
	get_move_two(angle, move);
}
