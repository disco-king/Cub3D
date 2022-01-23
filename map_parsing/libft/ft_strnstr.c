#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	int		need_l;

	if (*needle == '\0')
		return ((char *)haystack);
	count = 0;
	need_l = ft_strlen(needle);
	while (count <= len && haystack[count])
	{
		if (haystack[count] == *needle && count + need_l <= len)
			if (ft_strncmp(&(haystack[count]), needle, need_l) == 0)
				return ((char *)&haystack[count]);
		count++;
	}
	return (NULL);
}
