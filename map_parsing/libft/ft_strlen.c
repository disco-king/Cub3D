#include "libft.h"

int ft_strlen(const char *str)
{
	int i = 0;

	if(!str)
		return(0);
	while(str[i])
		i++;
	return(i);
}