/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:20:30 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/23 13:24:17 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	main(void)
{
	t_window	window;
	char		**map;

	window.player = malloc(sizeof(t_player));
	map = malloc(sizeof(char *) * 1000);
	map[0] = "111111111";
	map[1] = "101000001";
	map[2] = "100001001";
	map[3] = "10N000001";
	map[4] = "100000001";
	map[5] = "101000001";
	map[6] = "111111111";
	map[7] = NULL;
	window.map = map;
	window.player->angle = 0;
	init_window(&window, map);
	return (0);
}
