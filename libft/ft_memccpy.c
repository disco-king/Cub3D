/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:03:54 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:03:55 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				count;
	unsigned char		*dest;
	unsigned const char	*sorc;

	dest = dst;
	sorc = src;
	count = 0;
	while (count < n)
	{
		dest[count] = (unsigned char) sorc[count];
		if (sorc[count] == (unsigned char) c)
			break ;
		count++;
	}
	if (count == n)
		return (0);
	return (&(dest[count + 1]));
}
