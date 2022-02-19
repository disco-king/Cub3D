#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_dst;
	size_t	l_src;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (l_dst >= dstsize)
		return (dstsize + l_src);
	if (dstsize > l_dst + l_src)
		ft_memcpy(dst + l_dst, src, l_src + 1);
	else
	{
		ft_memcpy(dst + l_dst, src, dstsize - l_dst - 1);
		dst[dstsize - 1] = '\0';
	}
	return (l_src + l_dst);
}
