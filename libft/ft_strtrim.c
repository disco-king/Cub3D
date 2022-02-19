#include "libft.h"
#include <stdio.h>

static int	in_line(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	get_index(char const *s1, char const *set, int start)
{
	int	len;
	int	res;

	res = 0;
	len = ft_strlen(s1);
	if (start == 1)
	{
		while (in_line(set, *s1++))
			res++;
	}
	else
	{
		s1 += len - 1;
		res = len - 1;
		while (in_line(set, *s1--))
			res--;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*line;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = get_index(s1, set, 1);
	len = ft_strlen(s1);
	if (start == len)
		return (ft_strdup(""));
	end = get_index(s1, set, 0);
	line = malloc(end - start + 2);
	if (line == NULL)
		return (NULL);
	len = end - start + 1;
	end = 0;
	while (len)
	{
		line[end] = s1[end + start];
		end++;
		len--;
	}
	line[end] = '\0';
	return (line);
}
