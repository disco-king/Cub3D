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
