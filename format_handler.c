#include "ft_printf.h"

int		handle_format(const char *fstr, t_list **lst, va_list args)
{
	int i;
	char *percent;
	t_format *format;

	i = 0;
	format = init_format();
	ft_putendl(fstr);
	if (fstr[i] == '%')
	{
		i++;
		percent = ft_strdup("%");
		ft_lstaddend(lst, ft_lstnew(percent, ft_strlen(percent) + 1));
		free(percent);
	}
	else
	{
		i += handle_flags(fstr + i, format);
		i += handle_width(fstr + i, format, args);
	}
	print_format(format);
	free_format(&format);
	return (i);
}	