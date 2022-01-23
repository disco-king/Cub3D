#include "libft.h"

char	*ft_substr(const char *s, char sep)
{
	char	*str;
	int		lim;
	int		i;

	lim = 0;
	i = 0;
	if (*s == 34 || *s == 39)
	{
		sep = *s;
		s++;
	}
	while (s[lim] && s[lim] != sep)
		lim++;
	str = (char *)malloc(lim + 1);
	if (str)
	{
		while (lim--)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
