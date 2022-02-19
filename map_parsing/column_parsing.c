/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:55:33 by fmalphit          #+#    #+#             */
/*   Updated: 2022/02/19 12:19:12 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_column(t_list *lst, int i)
{
	int	flag;
	int	buff;

	flag = 2;
	while (lst)
	{
		if (i > ft_strlen(lst->content))
			buff = 2;
		else
			buff = get_value(lst->content[i], NULL);
		if (buff < 0 || flag - buff < -1
			|| flag - buff > 1)
			return (1);
		flag = buff;
		lst = lst->next;
	}
	if (flag <= 0)
		return (1);
	return (0);
}

int	column_empty(t_list *lst, int i)
{
	while (lst)
	{
		if (i < ft_strlen(lst->content)
			&& lst->content[i] != ' ')
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_lst(t_list *lst)
{
	int	max_len;
	int	empty;
	int	i;

	i = 0;
	empty = 0;
	max_len = get_max_len(lst);
	while (i < max_len)
	{
		if (!column_empty(lst, i))
		{
			if (check_column(lst, i) || empty == 2)
				return (1);
			empty = 1;
		}
		else if (empty)
			empty++;
		i++;
	}
	return (0);
}
