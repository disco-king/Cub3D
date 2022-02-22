/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:04:04 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:04:05 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*dest;
	const char	*sorc;

	dest = dst;
	sorc = src;
	count = 0;
	while (count < n)
	{
		dest[count] = sorc[count];
		count++;
	}
	return (dst);
}
