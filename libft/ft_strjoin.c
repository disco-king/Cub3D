#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(len1 + len2 + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(&new[len1], s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}
