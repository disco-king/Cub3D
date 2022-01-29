/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:20:30 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/26 13:28:37 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	main(void)
{
	t_window	window;
	char		**map;

	window.player = malloc(sizeof(t_player));
	map = malloc(sizeof(char *) * 1000);
	map[0] = "11111111111111111111";
	map[1] = "10000000000000000001";
	map[2] = "10000000000000000001";
	map[3] = "10000000000000000001";
	map[4] = "10000000000000000001";
	map[5] = "10000000000000000N01";
	map[6] = "11111111111111111111";
	map[7] = NULL;
	window.map = map;
	window.player->angle = 0;
	init_window(&window, map);
	return (0);
}
