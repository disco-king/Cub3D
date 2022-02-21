#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buff;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	buff = *lst;
	while (buff->next)
		buff = buff->next;
	buff->next = new;
}
