/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:43:55 by fmalphit          #+#    #+#             */
/*   Updated: 2022/02/19 12:19:09 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_name(char *name, int map)
{
	char	*str;
	int		len;

	len = ft_strlen(name);
	if (map)
		str = MAP;
	else
		str = TEXT;
	if (len <= 4)
		return (1);
	if (ft_strncmp(&(name[len - 4]), str, 5))
		return (1);
	return (0);
}

int	check_params(t_params *params)
{
	if (!params->no_addr || !params->we_addr
		|| !params->so_addr || !params->ea_addr
		|| params->c_col < 0 || params->f_col < 0)
		return (1);
	if (check_name(params->no_addr, 0)
		|| check_name(params->we_addr, 0)
		|| check_name(params->ea_addr, 0)
		|| check_name(params->so_addr, 0))
		return (1);
	return (0);
}
