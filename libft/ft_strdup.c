#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (str == 0)
		return (NULL);
	return ((char *)ft_memcpy(str, s1, len));
}
