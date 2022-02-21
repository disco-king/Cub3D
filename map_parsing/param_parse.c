/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:43:55 by fmalphit          #+#    #+#             */
/*   Updated: 2022/02/20 13:18:17 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse_color(char *color)
{
	int	i;
	int	buff;
	int	value;

	i = 0;
	value = 0;
	while (i < 3)
	{
		buff = ft_atoi(color);
		if (buff < 0 || buff > 255)
			return (-1);
		value += buff << 4 * (2 - i);
		while (*color <= 57 && *color >= 48)
			color++;
		i++;
		if (*color != ',')
			break ;
		color++;
	}
	if (i < 3)
		return (-1);
	else if (*color || color[-1] == ',')
		return (-1);
	return (value);
}

int	add_param(char **arr, t_params *params)
{
	if (!ft_strncmp(arr[0], "NO", 3) && params->no_addr == NULL)
		params->no_addr = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "WE", 3) && params->we_addr == NULL)
		params->we_addr = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "SO", 3) && params->so_addr == NULL)
		params->so_addr = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "EA", 3) && params->ea_addr == NULL)
		params->ea_addr = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "F", 2) && params->f_col == -1)
		params->f_col = parse_color(arr[1]);
	else if (!ft_strncmp(arr[0], "C", 2) && params->c_col == -1)
		params->c_col = parse_color(arr[1]);
	else
		return (1);
	return (0);
}

int	get_params(t_params *params, int fd)
{
	int		res;
	char	*str;
	char	**arr;

	arr = NULL;
	while (check_params(params))
	{
		res = get_next_line(fd, &str);
		if (res == 0)
			break ;
		if (!str)
			continue ;
		arr = ft_split(str, ' ');
		free(str);
		if (!arr || add_param(arr, params))
			break ;
		arr = free_all(arr);
	}
	free_all(arr);
	return (check_params(params));
}

void	init_params(t_params *params)
{
	params->c_col = -1;
	params->f_col = -1;
	params->no_addr = NULL;
	params->we_addr = NULL;
	params->so_addr = NULL;
	params->ea_addr = NULL;
}
