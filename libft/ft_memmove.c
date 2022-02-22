/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:04:07 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:04:08 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sorc;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = dst;
	sorc = src;
	if (dest < sorc)
		return (ft_memcpy (dst, src, len));
	dest += len;
	sorc += len;
	while (len--)
		*--dest = *--sorc;
	return (dst);
}
