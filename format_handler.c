#include "ft_printf.h"

int		handle_format(const char *fstr, t_list **lst, va_list args)
{
	int i;
	char *percent;
	t_format *format;

	i = 0;
	format = init_format();
	if (fstr[i] == '%')
	{
		i++;
		percent = ft_strdup("%");
		ft_lstaddend(lst, ft_lstnew(percent, ft_strlen(percent) + 1));
		free(percent);
	}
	else
	{
ft_putendl(fstr + i);
		i += handle_flags(fstr + i, format);
ft_putendl(fstr + i);
		i += handle_width(fstr + i, format, args);
ft_putendl(fstr + i);
		i += handle_precision(fstr + i, format, args);
ft_putendl(fstr + i);
		i += handle_size(fstr + i, format);
ft_putendl(fstr + i);
		i += handle_type(fstr +i, format);
	}
print_format(format);
	free_format(&format);
	return (i);
}	