#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	if (!lst || !*(lst))
		return ;
	free((*lst)->content);
	ft_lstfree(&((*lst)->next));
	free(*lst);
}