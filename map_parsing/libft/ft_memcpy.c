#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*dest;
	const char	*sorc;

	dest = dst;
	sorc = src;
	count = 0;
	while (count < n)
	{
		dest[count] = sorc[count];
		count++;
	}
	return (dst);
}
