/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:04:25 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:04:26 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_quotes(const char **str)
{
	const char	*ptr;
	char		quote;

	ptr = *str;
	quote = *ptr;
	ptr++;
	while (*ptr)
	{
		if (*ptr == quote)
			break ;
		ptr++;
	}
	if (!(*ptr))
		ptr--;
	*str = ptr;
}

static int	word_count(const char *str, char sep)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != sep && flag == 0)
		{
			if (*str == 34 || *str == 39)
				skip_quotes(&str);
			count++;
			flag++;
		}
		if (*str == sep)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*get_next_sep(const char *str, char sep)
{
	if (*str == 34 || *str == 39)
	{
		skip_quotes(&str);
		str++;
	}
	else
		while (*str != sep && *str)
			str++;
	return ((char *)str);
}

static int	check_malloc(char ***ret, int count)
{
	if (count == 0)
		return (1);
	*ret = (char **)malloc((count + 1) * sizeof(char *));
	if (!*ret)
		return (1);
	return (0);
}

char	**ft_split(const char *str, char c)
{
	int		count;
	char	**ret;
	char	*buff;
	int		i;

	count = word_count(str, c);
	if (check_malloc(&ret, count))
		return (NULL);
	ret[count] = NULL;
	i = count;
	count = 0;
	while (count < i)
	{
		while (*str == c)
			str++;
		buff = ft_substr((const char *)str, c);
		if (!buff)
			return (free_all(ret));
		ret[count] = buff;
		str = get_next_sep((const char *)str, c);
		count++;
	}
	return (ret);
}
