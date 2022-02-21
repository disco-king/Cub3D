#include "libft.h"

char	**free_all(char **ret)
{
	int	i;

	if (!ret)
		return (NULL);
	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		ret[i] = NULL;
		i++;
	}
	free(ret[i]);
	ret[i] = NULL;
	free(ret);
	return (NULL);
}
