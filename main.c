/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:20:30 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 12:02:08 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

char	**map_parsing(char *filename, t_params *params)
{
	int		fd;
	char	**map;

	if (check_name(filename, 1))
	{
		printf("Wrong file!\n");
		return (NULL);
	}
	init_params(params);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Fd error!\n");
		return (NULL);
	}
	if (get_params(params, fd))
	{
		printf("Params invalid!\n");
		return (NULL);
	}
	map = get_map(fd, &(params->height), &(params->width));
	if (!map)
		printf("Map invalid!\n");
	return (map);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_window	window;
	char		**map;

	window.player = malloc(sizeof(t_player));
	window.textures = malloc(sizeof(t_textures));
	map = map_parsing(argv[1], &params);
	window.params = &params;
	if (!map)
		exit(0);
	window.map = map;
	window.player->angle = 0;
	window.x_border = params.width;
	window.y_border = params.height;
	init_window(&window, map);
	return (0);
}
