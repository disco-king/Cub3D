/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:41:19 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 13:09:26 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	pix_to_img(t_data *data, int x, int y, int color)
{
	char	*addr;

	addr = data->cur_addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)addr = color;
}

void	get_new_image(void **new1, void **new2, t_window *win)
{
	*new1 = mlx_new_image(win->mlx, WIN_X, WIN_Y);
	win->img->addr[0] = mlx_get_data_addr(*new1, &(win->img->bits_per_pixel),
			&(win->img->line_length), &(win->img->endian));
	*new2 = mlx_new_image(win->mlx, WIN_X, WIN_Y);
	win->img->addr[1] = mlx_get_data_addr(*new2, &(win->img->bits_per_pixel),
			&(win->img->line_length), &(win->img->endian));
}
