#include "ft_printf.h"

int		print_lst(t_list *lst)
{
	int chars;

	if (!lst)
		return (0);
	chars = 0;
	while (lst)
	{
		ft_putstr((char *)lst->content);
		chars += ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (chars);
}