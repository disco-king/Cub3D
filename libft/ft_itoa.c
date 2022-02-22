/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:03:33 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:03:34 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dec(long n, int *sign)
{
	int	res;

	res = 0;
	*sign = 0;
	if (n < 0)
	{
		res++;
		*sign = 1;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		sign;
	long	l;

	l = n;
	len = ft_dec(n, &sign);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (NULL);
	if (sign)
	{
		l = l * -1;
		num[0] = '-';
	}
	num[len] = '\0';
	len--;
	while (len != sign - 1)
	{
		num[len] = (l % 10) + 48;
		l = l / 10;
		len--;
	}
	return (num);
}
