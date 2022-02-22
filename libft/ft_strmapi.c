/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:04:48 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:04:48 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		len;
	int		count;

	if (f == NULL || s == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	count = 0;
	while (count < len)
	{
		res[count] = f(count, s[count]);
		count++;
	}
	res[count] = '\0';
	return (res);
}
