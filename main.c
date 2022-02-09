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

char **map_parsing(char *filename, t_params *params)
{
	char **map;

	if(check_name(filename, 1))
	{
		printf("Wrong file!\n");
		return(NULL);
	}
	init_params(params);
	int fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		printf("Fd error!\n");
		return(NULL);
	}
	if(get_params(params, fd))
	{
		printf("Params invalid!\n");
		return(NULL);
	}

	map = check_map(fd, &(params->height), &(params->width));
	if(!map)
	{
		printf("Map invalid!\n");
		exit(1);
	}
	return(map);
}

int	main(int argc, char **argv)
{
	t_params params;
	t_window	window;
	char		**map;

	window.player = malloc(sizeof(t_player));
	map = map_parsing(argv[1], &params);
	if(!map)
		exit(0);
	window.map = map;
	window.player->angle = 0;
	/*map sizes now assigned from params (see parsing)*/
	window.x_border = params.width;
	window.y_border = params.height;
	init_window(&window, map);
	return (0);
}
