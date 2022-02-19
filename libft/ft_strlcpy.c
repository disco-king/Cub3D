#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	int		lim;

	lim = dstsize;
	s_len = ft_strlen(src);
	if (dstsize <= 0)
		return (s_len);
	if (s_len < dstsize)
		lim = s_len;
	while (lim--)
		*dst++ = *src++;
	return (s_len);
}
