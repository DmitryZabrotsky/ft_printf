#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	*lst;
	int		i;
	int		res;

	va_start(args, format);
	lst = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = i + handle_format(format + i, args, &lst); 
		}
		else
			i = i + handle_string(format + i, &lst);
	}
	va_end(args);
	res = print_lst(lst);
	ft_lstfree(&lst);
	return(res);
}	