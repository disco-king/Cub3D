/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:41:45 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/20 18:55:53 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

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
	void		*mlx;
	void		*window;
	int			floor_color;
	int			ceiling_color;
}	t_window;

void	init_window(t_window *window, char **map);
#endif
