/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:03:50 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:03:50 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*buff;

	if (lst == NULL)
		return (0);
	buff = lst;
	res = 1;
	while (buff -> next)
	{
		buff = buff -> next;
		res++;
	}
	return (res);
}
