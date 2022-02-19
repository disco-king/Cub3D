#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buff;

	if (lst == NULL)
		return (0);
	buff = lst;
	while (buff -> next)
		buff = buff -> next;
	return (buff);
}
