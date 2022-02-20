/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:20:30 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/20 13:57:22 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	error_exit(int code)
{
	if (code == 0)
		printf("Error!\nInvalid arguments!\n");
	if (code == 1)
		printf("Error!\nWrong file format!\n");
	if (code == 2)
		printf("Error!\nFile not opened!\n");
	if (code == 3)
		printf("Error!\nInvalid parameters!\n");
	if (code == 4)
		printf("Error!\nInvalid map!\n");
	if (code == 5)
		printf("Error!\nAllocation failed!\n");
	if (code == 6)
		printf("Error!\nInvalid textures!\n");
	if (code == 7)
		printf("Error!\nPlayer not found!\n");
	exit (code);
}

char	**map_parsing(char *filename, t_params *params)
{
	int		fd;
	char	**map;

	if (check_name(filename, 1))
		error_exit(1);
	init_params(params);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(2);
	if (get_params(params, fd))
		error_exit(3);
	map = get_map(fd, &(params->height), &(params->width));
	if (!map)
		error_exit(4);
	return (map);
}

void	ret_error(void *data)
{
	if (!data)
		error_exit(5);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_window	window;
	char		**map;

	if (argc != 2)
		error_exit(0);
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
