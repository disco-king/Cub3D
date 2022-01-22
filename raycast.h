/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:41:45 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/22 15:14:04 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	start_direction;
}	t_player;

typedef struct s_window
{
	t_player	*player;
	char		**map;
	void		*mlx;
	void		*window;
	int			floor_color;
	int			ceiling_color;
}	t_window;

void	init_window(t_window *window, char **map);
void	scale_map(int i, int j, t_window *window, int color);

/*simple hoooks*/

int		key_hook(int keycode, t_window *window);

/*draw_ray on map*/

void	count_ray(t_window *window, float xend, float yend, int color);
#endif
