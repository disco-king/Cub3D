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

	printf("north path %s\nwest path %s\nsouth path %s\neast path %s\n",
		params->no_addr, params->we_addr, params->so_addr, params->ea_addr);
	printf("floor %d\nceiling %d\n", params->f_col, params->c_col);

	map = check_map(fd, &(params->height), &(params->width));
	if(!map)
	{
		printf("Map invalid!\n");
		exit(1);
	}
	printf("height %d width %d\n", params->height, params->width);
	char **buff = map;
	while (*buff)
	{
		printf("%s$\n", *buff);
		buff++;
	}
	
	return(map);
}

int	main(int argc, char **argv)
{
	t_params params;
	t_window	window;
	char		**map;

	window.player = malloc(sizeof(t_player));
	window.params = malloc(sizeof(t_params));
	window.textures = malloc(sizeof(t_textures));
	//window.img = malloc(sizeof(t_data));
	map = map_parsing(argv[1], &params);
	window.params = &params;
	if(!map)
		exit(0);
	window.map = map;
	window.player->angle = 0;
	write(2, "assigned angle\n", 15);
	/*map sizes now assigned from params (see parsing)*/
	window.x_border = params.width;
	window.y_border = params.height;
	//printf("width %d height %d\n", window.x_border, window.y_border);
	init_window(&window, map);
	return (0);
}
