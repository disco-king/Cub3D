/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:05:44 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:43:41 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_next_line(int fd, char **line)
{
	char	c;
	int		res;
	char	*buff;

	*line = NULL;
	res = read(fd, &c, 1);
	while (res > 0 && c != '\n')
	{
		res = ft_strlen(*line);
		buff = malloc(sizeof(char) * (res + 2));
		ft_strlcpy(buff, *line, res);
		buff[res] = c;
		buff[res + 1] = 0;
		free(*line);
		*line = buff;
		res = read(fd, &c, 1);
	}
	return (res);
}
