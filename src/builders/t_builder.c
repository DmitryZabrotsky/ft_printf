#include "../../inc/ft_printf.h"

char	*build_t(va_list args)
{
	char	*res;
	t_list *lst;

	lst = (t_list *)(va_arg(args, t_list *));
	res = ft_strdup((char *)lst->content);
	ft_mleak(&res, ft_strjoin(res, " "));
	ft_mleak(&res, ft_strjoin(res, (ft_itoa(lst->content_size))));
	return (res);
}