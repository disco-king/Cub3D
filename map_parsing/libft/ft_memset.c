#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*ptr;

	count = 0;
	ptr = b;
	while (count < len)
	{
		ptr[count] = (unsigned char) c;
		count++;
	}
	return (b);
}
