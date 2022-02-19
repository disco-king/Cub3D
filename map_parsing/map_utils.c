/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:55:33 by fmalphit          #+#    #+#             */
/*   Updated: 2022/02/19 12:21:50 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*add_spaces(char *src, int max)
{
	int		len;
	char	*ret;

	len = ft_strlen(src);
	ret = malloc((sizeof(char)) * max + 1);
	ft_memcpy(ret, src, len);
	ft_memset(&(ret[len]), 32, max - len);
	ret[max] = 0;
	return (ret);
}

char	**lst_to_arr(t_list *lst, int *height, int *width)
{
	int		i;
	char	**ret;

	i = 0;
	*width = get_max_len(lst);
	*height = ft_lstsize(lst);
	ret = malloc(sizeof(char *) * (*height + 1));
	while (lst)
	{
		if (ft_strlen(lst->content) < *width)
			ret[i] = add_spaces(lst->content, *width);
		else
			ret[i] = ft_strdup(lst->content);
		if (!ret[i])
			return (free_all(ret));
		i++;
		lst = lst->next;
	}
	ret[i] = NULL;
	return (ret);
}
