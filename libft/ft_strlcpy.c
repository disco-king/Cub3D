/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:04:41 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:04:41 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	int		lim;

	lim = dstsize;
	s_len = ft_strlen(src);
	if (dstsize <= 0)
		return (s_len);
	if (s_len < dstsize)
		lim = s_len;
	while (lim--)
		*dst++ = *src++;
	return (s_len);
}
