/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:03:40 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:03:40 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfree(t_list *list)
{
	t_list	*buff;

	if (!list)
		return (NULL);
	buff = list->next;
	while (list->next)
	{
		free(list->content);
		free(list);
		list = buff;
		buff = buff->next;
	}
	free(list->content);
	free(list);
	return (NULL);
}
