/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:55:33 by fmalphit          #+#    #+#             */
/*   Updated: 2022/02/19 12:19:15 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	line_empty(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

int	check_line(const char *line)
{
	static int	character;
	int			flag;
	int			buff;

	flag = 2;
	while (*line)
	{
		buff = get_value(*line, &character);
		if (buff < 0 || flag - buff < -1
			|| flag - buff > 1)
			return (1);
		flag = buff;
		line++;
	}
	if (flag <= 0)
		return (1);
	return (0);
}

int	get_max_len(t_list *lst)
{
	int	max;
	int	buff;

	max = 0;
	while (lst)
	{
		buff = ft_strlen(lst->content);
		if (buff > max)
			max = buff;
		lst = lst->next;
	}
	return (max);
}
