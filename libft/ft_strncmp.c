/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:04:51 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:04:51 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const void *s1, const void *s2, size_t n)
{
	const char	*src1;
	const char	*src2;
	size_t		count;
	int			res;

	if (n == 0)
		return (0);
	src1 = s1;
	src2 = s2;
	count = 0;
	while (count < n)
	{
		if (src1[count] == '\0' && src2[count] == '\0')
			return (0);
		res = (unsigned char) src1[count] - (unsigned char) src2[count];
		if (res < 0)
			return (-1);
		if (res > 0)
			return (1);
		count ++;
	}
	return (res);
}
