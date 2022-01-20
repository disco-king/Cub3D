/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:42:31 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/20 17:47:23 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_window(t_window *window)
{
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, 1280, 720, "window");
	mlx_loop(window->mlx);
}
