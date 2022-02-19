/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:20:30 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 16:46:32 by fmalphit         ###   ########.fr       */
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

void	ret_error(void *data)
{
	if (!data)
	{
		printf("Error!\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_window	window;
	char		**map;

	if (argc == 1)
		exit(1);
	map = map_parsing(argv[1], &params);
	window.player = malloc(sizeof(t_player));
	ret_error(window.player);
	window.textures = malloc(sizeof(t_textures));
	ret_error(window.textures);
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
