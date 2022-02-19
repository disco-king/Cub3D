/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:55:33 by fmalphit          #+#    #+#             */
/*   Updated: 2022/02/19 12:40:51 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_value(char c, int *character)
{
	if (c == ' ' || c == 0)
		return (2);
	if (c == '1')
		return (1);
	if (c == '0')
		return (0);
	if (c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
	{
		if (!character || *character == 0)
		{
			if (character)
				*character = 1;
			return (0);
		}
	}
	return (-1);
}

int	get_line_lst(t_list **lines, int fd)
{
	int		res;
	int		empty;
	char	*line;

	empty = 0;
	res = get_next_line(fd, &line);
	while (res || line)
	{
		if (!line_empty(line))
		{
			if (check_line(line) || empty == 2)
				break ;
			empty = 1;
			ft_lstadd_back(lines, ft_lstnew(ft_strdup(line)));
		}
		else if (empty)
			empty++;
		free(line);
		res = get_next_line(fd, &line);
	}
	if (!res && !line)
		return (0);
	free (line);
	return (1);
}

char	**get_map(int fd, int *map_height, int *map_width)
{
	char	**map;
	t_list	*map_lines;

	map_lines = NULL;
	if (get_line_lst(&map_lines, fd)
		|| check_lst(map_lines))
	{
		ft_lstfree(map_lines);
		return (NULL);
	}
	map = lst_to_arr(map_lines, map_height, map_width);
	ft_lstfree(map_lines);
	return (map);
}
