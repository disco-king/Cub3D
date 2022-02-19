/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:18:41 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 17:07:30 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

char	*choose_texture(t_window *window)
{
	if (!window->side)
	{
		if (window->player->y > window->player->dir_y)
			return (window->textures->so);
		return (window->textures->no);
	}
	if (window->side)
	{
		if (window->player->x < window->player->dir_x)
			return (window->textures->ea);
		return (window->textures->we);
	}
	return (window->textures->no);
}

void	calc_texture_y(t_window *window, int wall_height,
						int draw_start, int draw_end)
{
	float	step;
	float	text_pos;
	int		y;
	t_data	img;
	int		*adr;

	step = (float)window->textures->text_height / (wall_height);
	text_pos = (draw_start - 720 / 2 - window->offset + wall_height / 2) * step;
	y = 0;
	while (y < draw_start)
		pix_to_img(window->img, window->current_x, y++, window->params->c_col);
	y = draw_start;
	adr = (int *) mlx_get_data_addr(choose_texture(window), &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (y < draw_end)
	{
		window->textures->text_y = (int)text_pos;
		text_pos += step;
		window->color = (adr[(int)(window->textures->text_height
					* window->textures->text_y + window->textures->text_x)]);
		pix_to_img(window->img, window->current_x, y, window->color);
		y++;
	}
}

void	calc_texture(t_window *window)
{
	if (window->side)
		window->textures->wall_x = window->player->dir_y;
	else if (!window->side)
		window->textures->wall_x = window->player->dir_x;
	window->textures->wall_x -= (floor)(window->textures->wall_x);
	window->textures->text_x = (int)(window->textures->wall_x
			* window->textures->text_width);
	if (window->side && window->player->dir_x > 0)
		window->textures->text_x
			= window->textures->text_width - window->textures->text_x - 1;
	if (!window->side && window->player->dir_y < 0)
		window->textures->text_x
			= window->textures->text_width - window->textures->text_x - 1;
}

void	get_texture(t_window *window)
{
	int	width;
	int	height;

	window->textures->no = mlx_xpm_file_to_image(window->mlx,
			window->params->no_addr,
			&width, &height);
	window->textures->ea = mlx_xpm_file_to_image(window->mlx,
			window->params->ea_addr,
			&width, &height);
	window->textures->so = mlx_xpm_file_to_image(window->mlx,
			window->params->so_addr,
			&width, &height);
	window->textures->we = mlx_xpm_file_to_image(window->mlx,
			window->params->we_addr,
			&width, &height);
	window->textures->text_width = width;
	window->textures->text_height = height;
	if (!window->textures->no || !window->textures->ea
		|| !window->textures->so || !window->textures->we)
	{
		write(2, "Error! Invalid textures\n", 25);
		exit (0);
	}
}
